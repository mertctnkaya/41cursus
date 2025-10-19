/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:57:12 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/19 20:09:39 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

// Quick sort algoritmasında elemanları bölmek için kullanılan fonksiyonlar içerir.

static void a_to_b_step(t_stack *s, int pivot, int threshold, int *rotated, int *pushed)
{
	// Stack A'dan Stack B'ye eleman taşır veya döndürür.
	if (s->a->index <= pivot)
	{
		pb(s, 1);	 // Stack A'dan Stack B'ye taşır.
		(*pushed)++; // Taşınan eleman sayısını artırır.
		if (s->b && s->b->index <= threshold)
			rb(&s->b, 1); // Eğer eleman threshold'un altındaysa, Stack B'yi döndürür.
	}
	else
	{
		ra(&s->a, 1); // Eğer eleman pivot'un üzerindeyse, Stack A'yı döndürür.
		(*rotated)++; // Döndürülen eleman sayısını artırır.
	}
}

void partition(t_stack *s, int pivot, int size)
{
	// Stack A'daki elemanları pivot'a göre böler.
	int i;
	int threshold;
	int rotated;

	threshold = pivot - (size / 4); // Threshold, pivot'un altındaki bir aralıktır.

	i = 0;
	rotated = 0;
	while (i < size)
	{
		if (s->a->index <= pivot)
		{
			pb(s, 1); // Stack A'dan Stack B'ye taşır.
			if (s->b && s->b->index <= threshold)
				rb(&s->b, 1); // Eğer eleman threshold'un altındaysa, Stack B'yi döndürür.
		}
		else
		{
			ra(&s->a, 1); // Eğer eleman pivot'un üzerindeyse, Stack A'yı döndürür.
		}
		i++;
	}
	while (rotated-- > 0)
		rra(&s->a, 1);
}

void partition_a_to_b(t_stack *s, int pivot, int size, int *pushed_to_b)
{
	// Stack A'daki elemanları pivot'a göre Stack B'ye böler.
	int i;
	int rotated;
	int threshold;

	threshold = pivot - (size / 4); // Threshold, pivot'un altındaki bir aralıktır.
	i = -1;
	rotated = 0;
	*pushed_to_b = 0;
	while (++i < size)
		a_to_b_step(s, pivot, threshold, &rotated, pushed_to_b);
	while (rotated-- > 0)
		rra(&s->a, 1); // Döndürülen elemanları eski konumlarına getirir.
}

void partition_b_to_a(t_stack *s, int pivot, int size, int *pushed_to_a)
{
	// Stack B'deki elemanları pivot'a göre Stack A'ya böler.
	int i;
	int rotated;

	i = -1;
	rotated = 0;
	*pushed_to_a = 0;
	while (++i < size)
	{
		if (s->b->index > pivot)
		{
			pa(s, 1);		  // Stack B'den Stack A'ya taşır.
			(*pushed_to_a)++; // Taşınan eleman sayısını artırır.
		}
		else
		{
			rb(&s->b, 1); // Stack B'yi döndürür.
			rotated++;
		}
	}
	while (rotated-- > 0)
		rrb(&s->b, 1); // Döndürülen elemanları eski konumlarına getirir.
}

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
