/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 20:09:52 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/07 22:32:26 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* sort_quick.c
** partition + restore (B -> A) mantığını içeren quick benzeri implementasyon
*/

#include "../../push_swap.h"

/* partition: pivot'tan küçük veya eşit olanları B'ye atar, büyükleri A'da döndürür */
void partition(t_stack *s, int pivot, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (s->a->index <= pivot)
		{
			pb(&s->a, &s->b, 1);
			s->size_a--;
			s->size_b++;
		}
		else
			ra(&s->a, 1);
		i++;
	}
}

/* rotate B to bring position 'pos' to top using minimal rotations */
static void rotate_b_to_top(t_stack *s, int pos)
{
	int moves;

	if (pos <= s->size_b / 2)
	{
		while (pos-- > 0)
			rb(&s->b, 1); /* rotate up */
	}
	else
	{
		moves = s->size_b - pos;
		while (moves-- > 0)
			rrb(&s->b, 1); /* rotate down */
	}
}

/* restore_sorted_from_b:
** - B'deki en küçükleri tek tek bul, B'de üstte getir, pa + ra ile A'nın altına ekle (append)
** - tüm küçükler append edildikten sonra A'nın en küçük elemanını başa getirmek için son bir döndürme yap
*/
void restore_sorted_from_b(t_stack *s)
{
	int pos;
	int min_pos;

	/* while B dolu iken: en küçük elemanı getir, A'ya pa, sonra ra ile altına koy */
	while (s->size_b > 0)
	{
		pos = find_min_pos(s->b); /* B içindeki min pozisyonunu bul */
		rotate_b_to_top(s, pos);  /* min'i B'nin tepesine getir */
		pa(&s->a, &s->b, 1);	  /* B->A */
		s->size_a++;
		s->size_b--;
		ra(&s->a, 1); /* pa ile gelen küçük elemanı A'nın altına koy */
	}
	/* şimdi A = [oldA..., appended smalls in ascending order]
	** en küçük öğe artık A'nın bir yerinde; onu başa getir */
	min_pos = find_min_pos(s->a);
	if (min_pos <= s->size_a / 2)
	{
		while (min_pos-- > 0)
			ra(&s->a, 1);
	}
	else
	{
		min_pos = s->size_a - min_pos;
		while (min_pos-- > 0)
			rra(&s->a, 1);
	}
}

/* quick sort ana fonksiyonu: pivot seç, partition, recursive, restore */
void quick_sort(t_stack *s)
{
	int pivot;
	int size;

	if (is_sorted(s->a))
		return;
	size = s->size_a;
	pivot = get_pivot(s->a, size); /* median pivot */
	partition(s, pivot, size);	   /* küçükleri B'ye at */
	quick_sort(s);				   /* A'daki büyükleri recursive sırala */
	restore_sorted_from_b(s);	   /* B'den düzgün şekilde geri getir */
}
