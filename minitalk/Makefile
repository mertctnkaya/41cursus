CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = libft.a printf.a

SRCS = server.c client.c
OBJS = $(SRCS:.c=.o)

all: $(SERVER) $(CLIENT)

server:
	rm -f server
	$(CC) $(CFLAGS) server.c -o server $(LIBS)
	./server

client:
	rm -f client
	$(CC) $(CFLAGS) client.c -o client $(LIBS)

clean:
	rm -f $(OBJS)
	rm -f server client

re: clean server client

.PHONY: all clean re