NAME = push_swap
SRC = push_swap.c \
sort.c

OBJ = $(SRC:.c=.o)

HEADER = push_swap.h

LIBFT_DIR = libft/
LIBFT = libft.a

CFLAGS = -g #-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	gcc $(CFLAGS) $(OBJ) $(LIBFT_DIR)$(LIBFT) -o $(NAME)

%.o: %.c $(HEADER)
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT) $(LIBFT_DIR)$(LIBFT)

re: fclean all