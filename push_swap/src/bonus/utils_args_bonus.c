/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:38:29 by mecetink          #+#    #+#             */
/*   Updated: 2025/11/07 14:56:41 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker_bonus.h"
#include "../../../libft/libft.h"

void	parse_arg(char *single, t_node **a, t_node **current, int *size)
{
	long	num;
	t_node	*new;

	if (single)
	{
		num = atol_check(single, *a, NULL);
		check_duplicates((int)num, *a, NULL);
		new = new_item((int)num, *a, NULL);
		append_item(a, current, new);
		(*size)++;
	}
}

void	parse_split(char **split_arr, t_node **a, t_node **current, int *size)
{
	long	num;
	int		i;
	t_node	*new;

	i = 0;
	while (split_arr[i])
	{
		num = atol_check(split_arr[i], *a, split_arr);
		check_duplicates((int)num, *a, split_arr);
		new = new_item((int)num, *a, split_arr);
		append_item(a, current, new);
		(*size)++;
		i++;
	}
}

void	free_split_arr(char **split_arr)
{
	int	i;

	i = 0;
	if (!split_arr)
		return ;
	while (split_arr[i])
	{
		free(split_arr[i]);
		i++;
	}
	free(split_arr);
}
