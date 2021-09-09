PUSH_SWAP = push_swap
CHECKER =  checker
COMMON_SRC = src/stack_builder.c src/common.c
SRC_PS = src/push_swap.c \
src/sort.c \
src/chunk_sort.c src/stack_a_instructions.c \
src/stack_b_instructions.c src/sort_utils.c \
src/chunk_sort_utils.c src/quicksort.c \
src/sort_three.c $(COMMON_SRC)
SRC_CHECKER = src/checker.c \
src/instructions.c get_next_line/get_next_line.c \
$(COMMON_SRC)

OBJ_PS = $(SRC_PS:.c=.o)
OBJ_CHECKER = $(SRC_CHECKER:.c=.o)

HEADER_PS = src/push_swap.h
HEADER_CHECKER = src/checker.h

LIBFT_DIR = libft/
LIBFT = libft.a

CFLAGS = -g -Wall -Werror -Wextra

all: $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP): $(OBJ_PS)
	@make --no-print-directory -C $(LIBFT_DIR)
	@gcc $(CFLAGS) $(OBJ_PS) $(LIBFT_DIR)$(LIBFT) -o $(PUSH_SWAP)
	@echo "\n\e[32m$@ built 📈\e[0m\n"

$(CHECKER): $(OBJ_CHECKER)
	@make --no-print-directory -C $(LIBFT_DIR)
	@gcc $(CFLAGS) $(OBJ_CHECKER) $(LIBFT_DIR)$(LIBFT) -o $(CHECKER)
	@echo "\n\e[32m$@ built 📉\e[0m\n"

%.o: %.c $(HEADER_PS) $(HEADER_CHECKER)
	@gcc $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_PS) $(OBJ_CHECKER) 
	@make --no-print-directory clean -C $(LIBFT_DIR)
	@echo "\n\e[31m object files removed 👋\e[0m\n"

fclean: clean
	@rm -f $(PUSH_SWAP) $(CHECKER)
	@rm -f $(LIBFT) $(LIBFT_DIR)$(LIBFT)
	@echo "\n\e[31m executables removed 👋\e[0m\n"

re: fclean all