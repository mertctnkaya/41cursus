/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 20:06:54 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/10 14:09:55 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	fill_array(t_item *a, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = a->index;
		a = a->next;
		i++;
	}
}

int	get_pivot(t_item *a, int size)
{
	int	arr[500];
	int	i;
	int	j;
	int	tmp;

	fill_array(a, arr, size);
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr[size / 2]);
}

int	find_min_pos(t_item *stack)
{
	int		min;
	int		pos;
	int		min_pos;
	t_item	*cur;

	if (!stack)
		return (0);
	cur = stack;
	min = cur->index;
	min_pos = 0;
	pos = 0;
	while (cur)
	{
		if (cur->index < min)
		{
			min = cur->index;
			min_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (min_pos);
}
