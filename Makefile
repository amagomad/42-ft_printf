# ---------- Config ---------- #
NAME    = libftprintf.a
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror

SRC     = src/ft_printf.c src/format.c src/utils/utils.c src/utils/utils2.c src/mapping/mapping.c src/mapping/mappiing.c
OBJ     = $(SRC:.c=.o)

LIBFT_DIR = includes/lib
LIBFT     = $(LIBFT_DIR)/libft.a

# ---------- Rules ---------- #
all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR) > /dev/null

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "✅ Built static library: $(NAME)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean > /dev/null
	@echo "🧼 Cleaning object files..."

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean > /dev/null
	@echo "🧼 Full clean (incl. lib)..."

re: fclean all

.PHONY: all clean fclean re
