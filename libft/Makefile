# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ksmorozo <ksmorozo@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/10 19:37:56 by ksmorozo      #+#    #+#                  #
#    Updated: 2021/07/07 13:57:57 by ksmorozo      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_split.c ft_strlen.c \
ft_strlcpy.c ft_strtrim.c \
ft_lstnew.c \
ft_isdigit.c ft_atol.c

OBJ = $(SRC:.c=.o)
HEADER = libft.h
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

%.o: %.c $(HEADER)
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re
