CFLAGS = -Wall -Wextra -Werror
CC = gcc
c_src = utils.c
c_obj=$(c_src:.c=.o)
all: server client

server:$(c_obj) minitalk.h
	$(CC) $(CFLAGS) server.c $(c_obj) -o server
client:$(c_obj) minitalk.h
	$(CC) $(CFLAGS) client.c $(c_obj) -o client

clean:
	rm -rf client server utils.o

fclean: clean

re : fclean all

.PHONY: all clean fclean re server client
