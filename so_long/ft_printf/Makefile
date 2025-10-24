NAME	=	libftprintf.a
SRCS	=	ft_printf.c \
			ft_intptr_handlers.c \
			ft_str_handlers.c \
			ft_libft_utils.c
OBJS	=	$(SRCS:.c=.o)
CC		=	cc -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o:		%.c
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re