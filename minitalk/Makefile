NAME	= client server
BNAME	= client_bonus server_bonus
CC		= cc -Wall -Wextra -Werror

SRCS	= server.c client.c
BSRCS	= server_bonus.c client_bonus.c

OBJS	= $(SRCS:.c=.o)
BOBJS	= $(BSRCS:.c=.o)

all: $(NAME)

bonus: $(NAME) $(BNAME)

$(NAME): $(OBJS)
	$(CC) server.o -o server
	$(CC) client.o -o client

$(BNAME): $(BOBJS)
	$(CC) server_bonus.o -o server_bonus
	$(CC) client_bonus.o -o client_bonus

%.o: %.c
	$(CC) -c $< -o $@

clean:
	@rm -f $(OBJS) $(BOBJS)

fclean: clean
	@rm -f client server client_bonus server_bonus

.PHONY: all bonus clean fclean re