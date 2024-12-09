# ============================================================================ #
#        ANSI color codes                                                      #
# ============================================================================ #

GREEN := \033[0;32m
YELLOW := \033[0;33m

BOLD_GREEN := \033[1;32m
BOLD_YELLOW := \033[1;33m

RESET := \033[0m
CLEAR_LINE := \033[K

# ============================================================================ #
#        Config variables                                                      #
# ============================================================================ #

NAME := push_swap
TEST_BIN := test_bin

CC := cc

# Directories
SRC_DIR := src
OBJ_DIR := obj
INC_DIR := include
LIB_DIR := libndav
LIB_INC_DIR := include
TEST_DIR := tests

# Flags
CFLAGS := -Wall -Wextra -I$(INC_DIR)
LIB_HEADER_FLAG := -I$(LIB_DIR)/$(LIB_INC_DIR)
LDFLAGS := -L$(LIB_DIR) -lndav $(LIB_HEADER_FLAG)
VALGRIND_FLAGS := --leak-check=full --show-leak-kinds=all
GDB_FLAGS := --args

# Sources and objects
SRC := ./src/error.c ./src/main.c ./src/operations/push.c ./src/operations/swap.c ./src/operations/rotate.c ./src/lists_utils.c ./src/parsing/parsing.c ./src/parsing/arg_check.c ./src/algo/push_swap.c
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
LIB := libndav.a

# Test sources and objects
TEST_SRC := ./tests/test_main.c
TEST_OBJ := $(patsubst $(TEST_DIR)/%.c, $(OBJ_DIR)/tests/%.o, $(TEST_SRC))
# Exclude main program from test
TEST_LINK_OBJ := $(filter-out $(OBJ_DIR)/$(NAME).o, $(OBJ)) $(TEST_OBJ)

# Test
TEST_ARGUMENTS := 2 4 1 3 5

# ============================================================================ #
#        Compilation rules                                                     #
# ============================================================================ #

all: $(NAME)

$(NAME): $(LIB_DIR)/$(LIB) msg_comp $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)
	@printf "$(GREEN)✔ $(NAME) created.\n$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(LIB_HEADER_FLAG) -o $@ -c $<

re: fclean all

# ============================================================================ #
#        Cleaning rules                                                        #
# ============================================================================ #

clean: msg_clean
	@rm -rf $(OBJ_DIR)

fclean: clean msg_fclean
	@rm -rf $(NAME)

# ============================================================================ #
#        Lib managing rules                                                    #
# ============================================================================ #

$(LIB_DIR)/$(LIB):
	@make -s -C $(LIB_DIR)

lclean:
	@make -s -C $(LIB_DIR) fclean

# ============================================================================ #
#        Test compilation rules                                                #
# ============================================================================ #

$(TEST_BIN): $(TEST_LINK_OBJ)
	@$(CC) $(CFLAGS) -o $@ $(TEST_LINK_OBJ) $(LDFLAGS)
	@printf "$(GREEN)✔ Binaire de test $(TEST_BIN) créé.\n$(RESET)"

$(OBJ_DIR)/$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(LIB_HEADER_FLAG) -c $< -o $@

# ============================================================================ #
#        Test rules                                                            #
# ============================================================================ #

test: $(TEST_BIN)
	@printf "$(YELLOW)Lancement des tests...\n$(RESET)"
	@./$(TEST_BIN)

val: CFLAGS += -g
val: libtest re
	valgrind $(VALGRIND_FLAGS) ./$(NAME) $(TEST_ARGUMENTS)

gdb: CFLAGS += -g
gdb: libtest re
	gdb $(GDB_FLAGS) ./$(NAME) $(TEST_ARGUMENTS)

libtest:
	@make -s -C $(LIB_DIR) test

# ============================================================================ #
#        Terminal message rules                                                #
# ============================================================================ #

msg_comp:
	@printf "$(YELLOW)Compiling $(NAME)... [$(CFLAGS)]\n$(RESET)"

msg_clean:
	@printf "$(YELLOW)Removing object files...\n$(RESET)"

msg_fclean:
	@printf "$(YELLOW)Removing $(NAME)...\n$(RESET)"

.PHONY: all clean fclean lclean re val gdb libtest msg_comp msg_clean msg_fclean
