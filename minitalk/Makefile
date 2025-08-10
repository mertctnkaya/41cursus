CC = cc -Wall -Wextra -Werror
SRCS = server.c client.c

all: server client

server: server.c
	rm -f server
	$(CC) server.c -o server
	./server

client: client.c
	rm -f client
	$(CC) client.c -o client

bs: server_bonus.c
	rm -f server_bonus
	$(CC) server_bonus.c -o server_bonus
	./server_bonus

bc: client_bonus.c
	rm -f client_bonus
	$(CC) client_bonus.c -o client_bonus

clean:
	rm -f server client server_bonus client_bonus o out a.out

re: clean server client

.PHONY: all clean re server client bc bs