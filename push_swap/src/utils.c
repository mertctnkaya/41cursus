/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 23:11:18 by mecetink          #+#    #+#             */
/*   Updated: 2025/11/06 18:32:57 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	parse_and_add_tokens(char *single, t_node **a,
					t_node **current, int *size, char **split_arr)
{
	long	num;
	int		i;
	t_node	*new;

	if (split_arr)
	{
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
	else if (single)
	{
		num = atol_check(single, *a, NULL);
		check_duplicates((int)num, *a, NULL);
		new = new_item((int)num, *a, NULL);
		append_item(a, current, new);
		(*size)++;
	}
}

void	free_split_arr(char **split_arr)
{
	int i = 0;

	if (!split_arr)
		return ;
	while (split_arr[i])
	{
		free(split_arr[i]);
		i++;
	}
	free(split_arr);
}

int	is_sorted(t_node *node)
{
	if (!node)
		return (1);
	while (node->next)
	{
		if (node->index > node->next->index)
			return (0);
		node = node->next;
	}
	return (1);
}

long	atol_check(const char *str, t_node *a, char **split_arr)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!(*str >= 48 && *str <= 57))
		raise_error(a, 0, split_arr);
	while ((*str >= 48 && *str <= 57))
	{
		res = res * 10 + (*str - '0');
		if ((unsigned long)res > (unsigned long)2147483647 + (sign < 0))
			raise_error(a, 0, split_arr);
		str++;
	}
	if (*str != '\0')
		raise_error(a, 0, split_arr);
	return (res * sign);
}
