/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:57:12 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/17 01:58:39 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

// Quick sort sonrası stack'leri eski haline getirmek için kullanılan fonksiyonlar içerir.

void rotate_b_to_top(t_stack *s, int pos)
{
	// Stack B'deki belirli bir pozisyondaki elemanı en üste taşır.
	int moves;

	if (pos <= s->size_b / 2)
	{
		while (pos-- > 0)
			rb(&s->b, 1); // Eğer eleman üst yarıdaysa, döndürme işlemi yapar.
	}
	else
	{
		moves = s->size_b - pos; // Eğer eleman alt yarıdaysa, ters döndürme işlemi yapar.
		while (moves-- > 0)
			rrb(&s->b, 1);
	}
}

void restore_sorted_from_b(t_stack *s)
{
	// Stack B'deki elemanları sıralı bir şekilde Stack A'ya taşır.
	int pos;
	int min_pos;

	while (s->size_b > 0)
	{
		pos = find_min_pos(s->b); // Stack B'deki minimum elemanın pozisyonunu bulur.
		rotate_b_to_top(s, pos);  // Minimum elemanı en üste taşır.
		pa(s, 1);				  // Stack B'den Stack A'ya taşır.
		ra(&s->a, 1);			  // Stack A'yı döndürür.
	}
	if (is_sorted(s->a))
		return;					  // Eğer Stack A sıralıysa, işlem yapmadan çıkar.
	min_pos = find_min_pos(s->a); // Stack A'daki minimum elemanın pozisyonunu bulur.
	if (min_pos <= s->size_a / 2)
	{
		while (min_pos-- > 0)
			ra(&s->a, 1); // Minimum elemanı en üste taşır.
	}
	else
	{
		while (min_pos++ < s->size_a)
			rra(&s->a, 1); // Minimum elemanı en üste taşır (ters döndürme).
	}
}

int find_max_pos(t_item *stack)
{
	// Stack'teki maksimum elemanın pozisyonunu bulur.
	int pos;
	int max_pos;
	int max;
	t_item *cur;

	if (!stack)
		return (0); // Eğer stack boşsa, 0 döner.
	cur = stack;
	max = cur->index; // İlk elemanı maksimum olarak varsayar.
	max_pos = 0;
	pos = 0;
	while (cur)
	{
		if (cur->index > max)
		{
			max = cur->index; // Daha büyük bir eleman bulursa, maksimumu günceller.
			max_pos = pos;	  // Maksimum elemanın pozisyonunu günceller.
		}
		cur = cur->next; // Bir sonraki elemana geçer.
		pos++;
	}
	return (max_pos); // Maksimum elemanın pozisyonunu döner.
}

void restore_by_max(t_stack *s)
{
	// Stack B'deki elemanları maksimuma göre Stack A'ya taşır.
	int pos;

	while (s->size_b > 0)
	{
		pos = find_max_pos(s->b); // Stack B'deki maksimum elemanın pozisyonunu bulur.
		rotate_b_to_top(s, pos);  // Maksimum elemanı en üste taşır.
		pa(s, 1);				  // Stack B'den Stack A'ya taşır.
	}
	if (!is_sorted(s->a))
		restore_final_sort(s); // Eğer Stack A sıralı değilse, son sıralama işlemini yapar.
}

void restore_final_sort(t_stack *s)
{
	// Stack A'yı tamamen sıralar.
	int min_pos;

	min_pos = find_min_pos(s->a); // Stack A'daki minimum elemanın pozisyonunu bulur.
	if (min_pos <= s->size_a / 2)
	{
		while (min_pos-- > 0)
			ra(&s->a, 1); // Minimum elemanı en üste taşır.
	}
	else
	{
		min_pos = s->size_a - min_pos;
		while (min_pos-- > 0)
			rra(&s->a, 1); // Minimum elemanı en üste taşır (ters döndürme).
	}
}
