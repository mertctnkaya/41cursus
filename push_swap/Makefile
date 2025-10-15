NAME		= push_swap
BONUS_EXE	= 
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
DEBUG		= 0

ifeq ($(DEBUG), 1)
	CFLAGS += -g -fsanitize=address
endif

SRC_FILES	= \
	src/main.c					\
	src/validation.c			\
	src/utils.c					\
	\
	src/operations/swap.c		\
	src/operations/push.c		\
	src/operations/rotate.c		\
	src/operations/rrotate.c	\
	\
	src/sorts/small.c			\
	src/sorts/medium.c			\
	\
	src/sorts/quick_sort/main.c	\
	src/sorts/quick_sort/utils.c	\
	src/sorts/quick_sort/small_chunks.c	\
	src/sorts/quick_sort/partition.c	\
	src/sorts/quick_sort/restore.c	\
	src/sorts/quick_sort/recursive.c

OBJ_DIR		= objs
OBJ_FILES	= $(SRC_FILES:src/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re