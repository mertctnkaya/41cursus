/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_login <your_login@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 00:00:00 by your_login       #+#    #+#             */
/*   Updated: 2025/10/23 00:00:00 by your_login      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
	{
		ft_printf("Error\nUsage: ./so_long <map.ber>\n");
		return (1);
	}
	ft_printf("Starting so_long with map: %s\n", argv[1]);
	if (game_init(&game) == -1)
	{
		ft_printf("Error\nFailed to initialize game\n");
		return (1);
	}
	mlx_loop(game.mlx);
	return (0);
}
