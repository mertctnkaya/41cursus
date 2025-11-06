NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = ./minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC_DIR = ./src
SRCS = $(SRC_DIR)/so_long.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB)
	@echo "Proje linkleniyor: $(NAME)"
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)
	@echo "--- so_long başarıyla derlendi! ---"

$(MLX_LIB):
	@echo "MiniLibX derleniyor..."
	@$(MAKE) -C $(MLX_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo ".o dosyaları siliniyor..."
	@rm -f $(OBJS)
	@$(MAKE) -C $(MLX_DIR) clean # MiniLibX içindeki .o'ları da temizler

fclean: clean
	@echo "Executable siliniyor..."
	@rm -f $(NAME)
	@echo "MiniLibX kütüphanesi (libmlx.a) siliniyor..."
	@rm -f $(MLX_LIB)

re: fclean all

.PHONY: all clean fclean re