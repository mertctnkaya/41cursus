/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 20:06:54 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/07 22:32:29 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* quick_utils.c
** pivot seçme ve B/A içinde min pozisyonu bulma yardımcıları
*/

#include "../../push_swap.h"

/* fill an int array with the first 'size' indices from stack a */
static void fill_array(t_item *a, int *arr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		arr[i] = a->index; /* index sıkıştırılmış değer */
		a = a->next;
		i++;
	}
}

/* get_pivot: basit median seçimi (array'i sıralayıp ortayı al) */
int get_pivot(t_item *a, int size)
{
	int arr[500];
	int i;
	int j;
	int tmp;

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
	return (arr[size / 2]); /* median döndür */
}

/* find_min_pos: stack'teki en küçük index'in 0-based pozisyonunu döndürür */
int find_min_pos(t_item *stack)
{
	int min;
	int pos;
	int min_pos;
	t_item *cur;

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
