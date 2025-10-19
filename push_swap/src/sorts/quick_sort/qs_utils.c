/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 20:06:54 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/19 12:27:24 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

int get_pivot(t_item *a, int size)
{
	t_item *cur;
	t_item *min;
	int i;
	int j;
	int pivot;

	i = 0;
	while (i < size / 2 + 1)
	{
		cur = a;
		min = NULL;
		j = 0;
		while (j < size)
		{
			if ((!min || cur->index < min->index) && cur->index != -1)
				min = cur;
			cur = cur->next;
			j++;
		}
		if (i == size / 2)
			pivot = min->index;
		min->index = -1;
		i++;
	}
	return (pivot);
}

int find_min_pos(t_item *stack)
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


int find_max_pos(t_item *stack)
{
	int pos;
	int max_pos;
	int max;
	t_item *cur;

	if (!stack)
		return (0);
	cur = stack;
	max = cur->index; // ilk elemanı max olarak varsayar
	max_pos = 0;
	pos = 0;
	while (cur)
	{
		if (cur->index > max)
		{
			max = cur->index;
			max_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (max_pos);
}
