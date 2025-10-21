NAME		= push_swap
BONUS_NAME	= checker
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
	src/sorts/qs_main.c			\
	src/sorts/qs_utils.c

CHC_FILES	= \
	src/checker/checker.c		\
	src/checker/extra_ops.c		\
	src/checker/checker_utils.c \
	\
	src/operations/push.c		\
	src/operations/rotate.c		\
	src/operations/rrotate.c	\
	src/operations/swap.c		\
	\
	src/utils.c					\
	src/validation.c

OBJ_DIR		= objs
SRC_OBJS	= $(SRC_FILES:src/%.c=$(OBJ_DIR)/%.o)
CHC_OBJS	= $(CHC_FILES:src/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(CHC_OBJS)
	$(CC) $(CFLAGS) $(CHC_OBJS) -o $(BONUS_NAME)

$(NAME): $(SRC_OBJS)
	$(CC) $(CFLAGS) $(SRC_OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re 