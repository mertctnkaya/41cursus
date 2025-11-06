NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

# color codes for pretty output
GREEN := \033[0;32m
YELLOW := \033[0;33m
RED := \033[0;31m
RESET := \033[0m

MLX_DIR = ./minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

PRINTF_DIR = ./ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
PRINTF_FLAGS = -L$(PRINTF_DIR) -lftprintf

SRC_DIR = ./src
SRCS = $(SRC_DIR)/so_long.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB) $(LIBFT) $(PRINTF_LIB)
	@printf '$(YELLOW)Proje linkleniyor: %s$(RESET)\n' "$(NAME)"
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) $(PRINTF_FLAGS) -o $(NAME)
	@printf '$(GREEN)--- so_long başarıyla derlendi! ---$(RESET)\n'

$(MLX_LIB):
	@printf '$(YELLOW)MiniLibX derleniyor...$(RESET)\n'
	@$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	@printf '$(YELLOW)Libft kütüphanesi derleniyor...$(RESET)\n'
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_LIB):
	@printf '$(YELLOW)ft_printf kütüphanesi derleniyor...$(RESET)\n'
	@$(MAKE) -C $(PRINTF_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf '$(YELLOW).o dosyaları siliniyor...$(RESET)\n'
	@rm -f $(OBJS)
	@$(MAKE) -C $(MLX_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	@printf '$(YELLOW)Executable siliniyor...$(RESET)\n'
	@rm -f $(NAME)
	@printf '$(YELLOW)MiniLibX kütüphanesi (libmlx.a) siliniyor...$(RESET)\n'
	@rm -f $(MLX_LIB)
	@printf '$(YELLOW)Libft kütüphanesi (libft.a) siliniyor...$(RESET)\n'
	@rm -f $(LIBFT)
	@printf '$(YELLOW)ft_printf kütüphanesi (libftprintf.a) siliniyor...$(RESET)\n'
	@rm -f $(PRINTF_LIB)

re: fclean all

.PHONY: all clean fclean re