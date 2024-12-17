NAME := libndav.a

CC := cc
CFLAGS := -Wall -Werror -Wextra -Iinclude

SRC_DIR := src
OBJ_DIR := obj

SRC := $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

GREEN := \033[0;32m
YELLOW := \033[0;33m
RESET_COLOR := \033[0m
CLEAR_LINE := \033[2K\r
TERM_UP := \033[1A

TOTAL_FILES := $(words $(OBJ))

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
	printf "$(TERM_UP)$(YELLOW)$$LEFT_TEXT$(RESET_COLOR)$$SPACES[$$BAR$$EMPTY_BAR]\n";
endef

all: $(NAME)
	@rm -f .compiled_count

$(NAME): $(OBJ)
	@ar rcs $@ $(OBJ)
	@printf "$(GREEN)✔ $(NAME) created.\n$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $<
	@$(update_progress_bar)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

test: CFLAGS += -g
test: all

.PHONY: all clean fclean re test
