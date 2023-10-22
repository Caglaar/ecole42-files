RM = rm -rf
CC = gcc
FLAG = -Wall -Wextra -Werror
CMPL = $(CC) $(FLAG)
CLIENT = @$(CMPL) client.c utils.c -o client
SERVER = @$(CMPL) server.c utils.c -o server
CLIENTBONUS = @$(CMPL) client_bonus.c utils.c -o client_bonus
SERVERBONUS = @$(CMPL) server_bonus.c utils.c -o server_bonus

all: client server
client:
	$(CLIENT)
server:
	$(SERVER)
bonus: client_bonus server_bonus
client_bonus:
	$(CLIENTBONUS)
server_bonus:
	$(SERVERBONUS)
clean:
	@$(RM) client server client_bonus server_bonus
norm:
	@norminette *.c *.h
run: re
	@./server
brun: clean bonus
	@./server_bonus
fclean: clean
re: clean all
.PHONY: all bonus clean fclean re