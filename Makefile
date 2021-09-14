PUSH_SWAP = push_swap
CHECKER =  checker
COMMON_SRC = src/stack_builder.c src/common.c \
src/freeing.c

SRC_PS = src/push_swap/push_swap.c \
src/push_swap/sort.c \
src/push_swap/chunk_sort.c src/push_swap/stack_a_instructions.c \
src/push_swap/stack_b_instructions.c src/push_swap/sort_utils.c \
src/push_swap/chunk_sort_utils.c src/push_swap/quicksort.c \
src/push_swap/sort_three.c $(COMMON_SRC)

SRC_CHECKER = src/checker/checker.c \
src/checker/stack_b_instructions.c get_next_line/get_next_line.c \
src/checker/stack_a_instructions.c src/checker/common_instructions.c \
src/checker/applying_instructions.c src/checker/initialiser.c \
$(COMMON_SRC)

OBJ_PS = $(SRC_PS:.c=.o)
OBJ_CHECKER = $(SRC_CHECKER:.c=.o)

HEADER_PS = src/push_swap/push_swap.h
HEADER_CHECKER = src/checker/checker.h

LIBFT_DIR = libft/
LIBFT = libft.a

CFLAGS = -g -Wall -Werror -Wextra

all: $(PUSH_SWAP) $(CHECKER)

$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR)
	@mv $(LIBFT_DIR)$(LIBFT) .

$(PUSH_SWAP): $(LIBFT) $(OBJ_PS)
	@gcc $(CFLAGS) $(OBJ_PS) $(LIBFT) -o $(PUSH_SWAP)
	@echo "\n\e[32m$@ built 📈\e[0m\n"

$(CHECKER): $(LIBFT) $(OBJ_CHECKER)
	@gcc $(CFLAGS) $(OBJ_CHECKER) $(LIBFT) -o $(CHECKER)
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