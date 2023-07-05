# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcaglar <Mcaglar@student.42kocaeli.com.tr  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 17:12:59 by mcaglar           #+#    #+#              #
#    Updated: 2023/07/05 17:13:51 by mcaglar          ###   ########.tr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAG = -Wall -Wextra -Werror
SRC = $(shell find . ! -name "ft_lst*.c" -name "ft_*.c")
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME):
	gcc $(FLAG) -c $(SRC)
	ar rc $(NAME) *.o
clean:
	/bin/rm -f  *.o
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all

.PHONY: all bonus clean fclean re
