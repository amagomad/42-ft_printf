# ---------- Colors ---------- #
DEF     = \033[0m
BOLD    = \033[1m
RED     = \033[38;5;124m
GREEN   = \033[38;5;155m

# ---------- Compiler ---------- #
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -fPIC
LIBRARY = libft.a

# ---------- Paths ---------- #
SRC_PATH = src/
CHAR_PATH = $(SRC_PATH)char/
IS_PATH   = $(SRC_PATH)is/
LST_PATH  = $(SRC_PATH)lst/
MEM_PATH  = $(SRC_PATH)mem/
PUT_PATH  = $(SRC_PATH)put/

SRC_CHAR = $(addprefix $(CHAR_PATH), ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
	ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_strdup.c ft_substr.c \
	ft_strjoin.c ft_strtrim.c ft_split.c ft_striteri.c ft_strmapi.c ft_strlen.c \
	ft_strcmp.c append_char.c ft_charinstr.c ft_strcpy.c)

SRC_IS = $(addprefix $(IS_PATH), ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c)

SRC_LST = $(addprefix $(LST_PATH), ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstadd_front.c \
	ft_lstaddback.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c)

SRC_MEM = $(addprefix $(MEM_PATH), ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_calloc.c ft_memcmp.c ft_memchr.c)

SRC_PUT = $(addprefix $(PUT_PATH), ft_atoi.c ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c \
	ft_putstr_fd.c ft_putnbr_fd.c ft_putchar.c ft_putstr.c ft_puthex.c ft_uitoa.c ft_uitoa_base.c \
	ft_uputnbr.c ft_putnbr.c ft_putptr.c)

SRC = $(SRC_CHAR) $(SRC_IS) $(SRC_LST) $(SRC_MEM) $(SRC_PUT)
OBJ = $(SRC:.c=.o)

# ---------- Rules ---------- #
all: $(LIBRARY)

$(LIBRARY): $(OBJ)
	@ar rcs $(LIBRARY) $(OBJ)
	@echo "$(GREEN)✅ Built: $(LIBRARY)$(DEF)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "$(RED)🧼 Cleaned objects$(DEF)"

fclean: clean
	@rm -f $(LIBRARY)
	@echo "$(RED)🧼 Removed lib: $(LIBRARY)$(DEF)"

re: fclean all

.PHONY: all clean fclean re
