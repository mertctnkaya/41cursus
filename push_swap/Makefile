NAME		= push_swap
CC			= cc -Wall -Wextra -Werror

SRC_FILES	= \
	src/main.c \
	src/validation.c \
	src/swap_ops.c \
	src/push_ops.c \
	src/rotate_ops.c \
	src/rrotate_ops.c \
	src/small_sort_alg.c \
	src/medium_sort_alg.c \
	src/large_sort_alg.c \
	src/sort_main.c 
	
OBJ_FILES	= $(SRC_FILES:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(NAME)

%.o:		%.c
	$(CC) -c $< -o $@

clean:
	@rm -f $(OBJ_FILES)

fclean:		clean
	@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re