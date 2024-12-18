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
#        Main rules                                                            #
# ============================================================================ #

all: $(NAME)

$(NAME): $(LIB_DIR)/$(LIB) $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)
	@printf "\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $<
	@./update_progress_bar.sh "Compiling $(NAME):"

re: libre fclean all

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

# ============================================================================ #
#        Library rules                                                         #
# ============================================================================ #

$(LIB_DIR)/$(LIB):
	@$(MAKE) -s -C $(LIB_DIR)

libre:
	@$(MAKE) -s -C $(LIB_DIR) re

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
