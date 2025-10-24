/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_login <your_login@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 00:00:00 by your_login       #+#    #+#             */
/*   Updated: 2025/10/23 00:00:00 by your_login      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../mlx_linux/mlx.h"
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

// Window size
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

// Tile size
#define TILE_SIZE 64

// Key codes for Linux
#define KEY_ESC 65307
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_UP 65362
#define KEY_LEFT 65361
#define KEY_DOWN 65364
#define KEY_RIGHT 65363

// Game structures
typedef struct s_game
{
	void *mlx;
	void *win;
	int width;
	int height;
} t_game;

// Function prototypes
int game_init(t_game *game);
void game_loop(t_game *game);
int close_game(t_game *game);

#endif
