/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 22:32:19 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/17 01:52:06 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// Orta boyutlu sıralama işlemleri için fonksiyonlar içerir.

void bring_to_top(t_item **a, int index, int size_a)
{
	// Belirtilen index'e sahip elemanı stack'in en üstüne taşır.
	int pos;
	t_item *temp;

	pos = 0;
	temp = *a;
	while (temp)
	{
		if (temp->index == index)
			break;		   // İstenen index bulunduğunda döngüden çıkar.
		temp = temp->next; // Bir sonraki elemana geçer.
		pos++;			   // Pozisyonu artırır.
	}
	if (pos <= size_a / 2)
	{
		// Eğer eleman stack'in üst yarısındaysa, yukarı kaydırır.
		while (pos-- > 0)
			ra(a, 1); // Rotate işlemi.
	}
	else
	{
		// Eğer eleman stack'in alt yarısındaysa, aşağı kaydırır.
		pos = size_a - pos;
		while (pos-- > 0)
			rra(a, 1); // Reverse rotate işlemi.
	}
}

static int check_special_4(t_stack *s)
{
	// Özel durumları kontrol eder ve uygun işlemleri yapar.
	if (match_case(s->a, (int[]){3, 2, 0, 1}))
		return (do_operations(s, 8)); // Özel durum 1 için işlemler.
	if (match_case(s->a, (int[]){0, 2, 3, 1}))
		return (do_operations(s, 4 | 1)); // Özel durum 2 için işlemler.
	if (match_case(s->a, (int[]){0, 3, 1, 2}))
		return (do_operations(s, 1 | 2)); // Özel durum 3 için işlemler.
	if (match_case(s->a, (int[]){3, 1, 2, 0}))
		return (do_operations(s, 2 | 4)); // Özel durum 4 için işlemler.
	return (0);							  // Hiçbir özel durum yoksa, 0 döner.
}

void sort_4(t_stack *s)
{
	if (is_sorted(s->a))
		return;
	if (check_special_4(s))
		return;
	bring_to_top(&s->a, 0, s->size_a);
	if (is_sorted(s->a))
		return;
	pb(s, 1);
	sort_3(&s->a);
	pa(s, 1);
}

static void push_smallest_two(t_stack *s)
{
	bring_to_top(&s->a, 0, s->size_a);
	pb(s, 1);
	bring_to_top(&s->a, 1, s->size_a);
	pb(s, 1);
}

void sort_5(t_stack *s)
{
	if (is_sorted(s->a))
		return;
	push_smallest_two(s);
	sort_3(&s->a);
	if (s->b->index < s->b->next->index)
		sb(&s->b, 1);
	pa(s, 1);
	pa(s, 1);
}
