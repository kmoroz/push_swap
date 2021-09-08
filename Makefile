PUSH_SWAP = push_swap
CHECKER =  checker
SRC_PS = src/push_swap.c \
src/sort.c
SRC_CHECKER = src/checker.c \
src/instructions.c get_next_line/get_next_line.c \

OBJ_PS = $(SRC_PS:.c=.o)
OBJ_CHECKER = $(SRC_CHECKER:.c=.o)

HEADER_PS = src/push_swap.h
HEADER_CHECKER = src/checker.h

LIBFT_DIR = libft/
LIBFT = libft.a

CFLAGS = -g #-Wall -Werror -Wextra

all: $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP): $(OBJ_PS)
	@make -C $(LIBFT_DIR)
	@gcc $(CFLAGS) $(OBJ_PS) $(LIBFT_DIR)$(LIBFT) -o $(PUSH_SWAP)
	@echo "\e[32m$@ built 📈\e[0m\n"

$(CHECKER): $(OBJ_CHECKER)
	@make -C $(LIBFT_DIR)
	@gcc $(CFLAGS) $(OBJ_CHECKER) $(LIBFT_DIR)$(LIBFT) -o $(CHECKER)
	@echo "\e[32m$@ built 📉\e[0m\n"

%.o: %.c $(HEADER_PS) $(HEADER_CHECKER)
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_PS) $(OBJ_CHECKER) 
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(PUSH_SWAP) $(CHECKER)
	rm -f $(LIBFT) $(LIBFT_DIR)$(LIBFT)

re: fclean all