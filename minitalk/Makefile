CC = cc -Wall -Wextra -Werror
SRCS = server.c client.c

all: server client

server: server.c utils.c
	rm -f server
	$(CC) server.c utils.c -o server
	./server

client: client.c utils.c
	$(CC) client.c utils.c -o client

bonusserver: server_bonus.c
	rm -f server_bonus
	$(CC) server_bonus.c utils.c -o server_bonus
	./server_bonus

bonusclient: client_bonus.c
	rm -f client_bonus
	$(CC) client_bonus.c utils.c -o client_bonus

clean:
	rm -f server client server_bonus client_bonus o out a.out

re: clean server client

.PHONY: all clean re server client