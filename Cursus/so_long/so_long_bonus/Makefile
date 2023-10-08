NAME			=	so_long

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar
ARFLAGS 		=	rcs
RM				=	rm -rf

SRC				=	so_long.c \
						open_maps.c \
						map_control.c \
						open_maps2.c \
						map_control2.c \
						free.c \
						movement.c \


LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH		=	./minilibx

all:				$(NAME)

$(NAME):			$(LIBFT) $(SRC) libmlx.a
					$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIBFT) -framework OpenGL -framework AppKit libmlx.a -Lminilibx

$(LIBFT):
					make -C $(LIBFT_PATH) all

libmlx.a:
					make -C $(MINILIBX_PATH) all
					mv $(MINILIBX_PATH)/libmlx.a .

clean:
					make -C $(LIBFT_PATH) clean
					make -C $(MINILIBX_PATH) clean

fclean:				clean
					make -C $(LIBFT_PATH) fclean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re libft
