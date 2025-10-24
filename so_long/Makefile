NAME		= so_long

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -f

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= includes

SRCS		= main.c \
			  game_init.c
#			  game_loop.c \
#			  map_parser.c \
#			  map_validator.c \
#			  player_movement.c \
#			  render.c \
#			  utils.c

# Add src/ prefix to source files
SRC_FILES	= $(addprefix $(SRC_DIR)/, $(SRCS))

# Object files
OBJS		= $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Header files
INCLUDES	= -I $(INC_DIR) -I $(MLX_DIR) -I $(LIBFT_DIR) -I $(FT_PRINTF_DIR)

# MinilibX (mlx_linux)
MLX_DIR		= mlx_linux
MLX_LIB		= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L $(MLX_DIR) -lmlx -lXext -lX11 -lm

# Libft
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

# ft_printf
FT_PRINTF_DIR	= ./ft_printf
FT_PRINTF		= $(FT_PRINTF_DIR)/libftprintf.a

# Colors for pretty output
GREEN		= \033[0;32m
RED			= \033[0;31m
YELLOW		= \033[0;33m
RESET		= \033[0m

# **************************************************************************** #
#                                 RULES                                        #
# **************************************************************************** #

# Default rule
all: $(MLX_LIB) $(LIBFT) $(FT_PRINTF) $(NAME)

# Build the final program
$(NAME): $(OBJS)
	@echo "$(YELLOW)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT) $(FT_PRINTF) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) created successfully!$(RESET)"

# Compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Build MinilibX
$(MLX_LIB):
	@echo "$(YELLOW)Building MinilibX...$(RESET)"
	@make -C $(MLX_DIR) 2>/dev/null || true
	@echo "$(GREEN)✓ MinilibX built!$(RESET)"

# Build libft
$(LIBFT):
	@echo "$(YELLOW)Building libft...$(RESET)"
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN)✓ libft built!$(RESET)"

# Build ft_printf
$(FT_PRINTF):
	@echo "$(YELLOW)Building ft_printf...$(RESET)"
	@make -C $(FT_PRINTF_DIR)
	@echo "$(GREEN)✓ ft_printf built!$(RESET)"

# Clean object files
clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@$(RM) -r $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(FT_PRINTF_DIR) clean
	@make -C $(MLX_DIR) clean 2>/dev/null || true
	@echo "$(GREEN)✓ Clean complete!$(RESET)"

# Clean everything including executables and libraries
fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(FT_PRINTF_DIR) fclean
	@echo "$(GREEN)✓ Full clean complete!$(RESET)"

# Rebuild everything
re: fclean all

# Phony targets (not actual files)
.PHONY: all clean fclean re