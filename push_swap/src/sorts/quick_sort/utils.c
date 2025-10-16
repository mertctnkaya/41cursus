/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 20:06:54 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/17 02:01:15 by mecetink         ###   ########.fr       */
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

	for (i = 0; i < size / 2 + 1; i++)
	{
		cur = a;
		min = NULL;
		for (j = 0; j < size; j++)
		{
			if ((!min || cur->index < min->index) && cur->index != -1)
				min = cur;
			cur = cur->next;
		}
		if (i == size / 2)
			pivot = min->index;
		min->index = -1;
	}
	return (pivot);
}

int find_min_pos(t_item *stack)
{
	// Stack'teki minimum elemanın pozisyonunu bulur.
	int min;
	int pos;
	int min_pos;
	t_item *cur;

	if (!stack)
		return (0); // Eğer stack boşsa, 0 döner.
	cur = stack;
	min = cur->index; // İlk elemanı minimum olarak varsayar.
	min_pos = 0;
	pos = 0;
	while (cur)
	{
		if (cur->index < min)
		{
			min = cur->index; // Daha küçük bir eleman bulursa, minimumu günceller.
			min_pos = pos;	  // Minimum elemanın pozisyonunu günceller.
		}
		cur = cur->next; // Bir sonraki elemana geçer.
		pos++;
	}
	return (min_pos); // Minimum elemanın pozisyonunu döner.
}
