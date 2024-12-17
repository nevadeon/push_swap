# ============================================================================ #
#        Variables                                                             #
# ============================================================================ #

NAME := push_swap

CC := cc

# Directories
SRC_DIR := src
OBJ_DIR := obj
INC_DIR := include

# Flags
CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR) -I$(LIB_DIR)/$(INC_DIR)
LDFLAGS = -L$(LIB_DIR) -lndav

# Sources and objects
SRC := src/error.c src/parsing/arguments_checks.c src/parsing/parsing.c src/main.c src/utils/lists.c src/utils/number_lists.c src/utils/numbers.c src/stack_operations/push.c src/stack_operations/rotate.c src/stack_operations/swap.c src/stack_operations/apply_instructions.c src/stack_operations/min_on_top.c src/algorithm/turk/instructions_selection.c src/algorithm/turk/instructions_initialisation.c src/algorithm/turk/algorithm.c src/algorithm/sort_size3_stack.c
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# Library
LIB := libndav.a
LIB_DIR := libndav

# Tests
TEST_BIN := test_bin
TEST_DIR := tests
TEST_SRC := tests/test_main.c tests/test.c
TEST_OBJ := $(patsubst $(TEST_DIR)/%.c, $(OBJ_DIR)/$(TEST_DIR)/%.o, $(TEST_SRC))
TEST_LINK_OBJ := $(filter-out $(OBJ_DIR)/main.o, $(OBJ)) $(TEST_OBJ)

# Tests flags
DEBUG_CFLAGS := -g
TEST_CFLAGS := -I$(TEST_DIR)/$(INC_DIR) -DINCLUDE_TEST_HEADER
VALGRIND_FLAGS := --quiet --leak-check=full --show-leak-kinds=all
GDB_FLAGS := --quiet --args

TEST_ARGS := 99 0 25 -38 10 7 42

# ============================================================================ #
#        ANSI color codes                                                      #
# ============================================================================ #

GREEN := \033[0;32m
YELLOW := \033[0;33m

RESET_COLOR := \033[0m
CLEAR_LINE := \033[2K\r
TERM_UP := \033[1A

# ============================================================================ #
#         Progress bar                                                         #
# ============================================================================ #

TOTAL_FILES     := $(words $(OBJ))
COMPILED_COUNT  := 0

define update_progress_bar
    @if [ ! -f .compiled_count ]; then \
        echo 0 > .compiled_count; \
        printf "\n"; \
    fi; \
    COMPILED_COUNT=$$(cat .compiled_count); \
    COMPILED_COUNT=$$((COMPILED_COUNT + 1)); \
    echo $$COMPILED_COUNT > .compiled_count; \
    PROGRESS=$$((COMPILED_COUNT * 100 / $(TOTAL_FILES))); \
    BAR_LENGTH=40; \
    FILLED=$$((PROGRESS * BAR_LENGTH / 100)); \
    EMPTY=$$((BAR_LENGTH - FILLED)); \
    BAR=$$(printf "%0.s#" $$(seq 1 $$FILLED)); \
    EMPTY_BAR=$$(printf "%0.s-" $$(seq 1 $$EMPTY)); \
    if [ $$EMPTY -eq 0 ]; then \
        EMPTY_BAR=""; \
    fi; \
	LEFT_TEXT="Compiling $(NAME)..."; \
    LEFT_TEXT_LENGTH=$$(echo -n $$LEFT_TEXT | wc -m); \
	TERMINAL_SIZE=$$(tput cols); \
	SPACE_NUMBER=$$((TERMINAL_SIZE - LEFT_TEXT_LENGTH - BAR_LENGTH - 2)); \
    SPACES=$$(printf "%0.s " $$(seq 1 $$SPACE_NUMBER)); \
    printf "$(TERM_UP)$(CLEAR_LINE)$(YELLOW)$$LEFT_TEXT$(RESET_COLOR)$$SPACES[$$BAR$$EMPTY_BAR]\n";
endef

# ============================================================================ #
#        Main rules                                                            #
# ============================================================================ #

all: $(NAME)
	@rm -f .compiled_count

$(NAME): $(LIB_DIR)/$(LIB) $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)
	@printf "$(GREEN)✔ $(NAME) created.\n$(RESET_COLOR)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $<
	@$(call update_progress_bar)

re: fclean all

clean:
	@printf "$(YELLOW)Removing object files...\n$(RESET_COLOR)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@printf "$(YELLOW)Removing $(NAME)...\n$(RESET_COLOR)"
	@rm -f $(NAME)

# ============================================================================ #
#        Library rules                                                         #
# ============================================================================ #

$(LIB_DIR)/$(LIB):
	@$(MAKE) -s -C $(LIB_DIR)

lclean:
	@$(MAKE) -s -C $(LIB_DIR) fclean

# ============================================================================ #
#        Test rules                                                            #
# ============================================================================ #

$(TEST_BIN): $(TEST_LINK_OBJ)
	@$(CC) $(CFLAGS) -o $@ $(TEST_LINK_OBJ) $(LDFLAGS)
	@printf "$(GREEN)✔ Binaire de test $(TEST_BIN) créé.\n$(RESET_COLOR)"

$(OBJ_DIR)/$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

test: CFLAGS += $(TEST_CFLAGS)
test: $(TEST_BIN)
	@printf "$(YELLOW)Lancement des tests...\n$(RESET_COLOR)"
	@./$(TEST_BIN)

valgrind: CFLAGS += $(DEBUG_CFLAGS)
valgrind: libtest re
	valgrind $(VALGRIND_FLAGS) ./$(NAME) $(TEST_ARGS)

gdb: CFLAGS += $(DEBUG_CFLAGS)
gdb: libtest re
	gdb $(GDB_FLAGS) ./$(NAME) $(TEST_ARGS)

libtest:
	@make -s -C $(LIB_DIR) test

# ============================================================================ #
#        Phony                                                                 #
# ============================================================================ #

.PHONY: all clean fclean lclean re valgrind gdb libtest
