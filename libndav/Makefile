NAME := libndav.a

CC := cc
CFLAGS := -Wall -Werror -Wextra -Iinclude

SRC_DIR := src
OBJ_DIR := obj

SRC := $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $<
	@./update_progress_bar.sh "Compiling $(NAME):"

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

test: CFLAGS += -g
test: all

.PHONY: all clean fclean re test
