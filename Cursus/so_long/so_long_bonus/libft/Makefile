NAME	= libft.a

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -g

FILES	= *.c get_next_line/*.c printf/*.c

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(FILES)
	ar -rc $(NAME) *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
