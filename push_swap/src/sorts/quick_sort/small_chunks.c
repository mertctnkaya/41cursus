/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_small_chunks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:57:12 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/14 23:57:12 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

// Küçük boyutlu stack'ler için sıralama işlemleri içerir.

void sort_small_a(t_stack *s, int size)
{
	// Stack A'daki küçük boyutlu elemanları sıralar.
	if (size <= 1 || is_sorted(s->a))
		return; // Eğer sıralanacak eleman yoksa veya zaten sıralıysa, işlem yapmadan çıkar.
	if (size == 2)
	{
		sort_2(&s->a); // 2 eleman için özel sıralama.
		return;
	}
	if (size == 3)
	{
		sort_3(&s->a); // 3 eleman için özel sıralama.
		return;
	}
}

void sort_small_b(t_stack *s, int size)
{
	// Stack B'deki küçük boyutlu elemanları sıralar.
	if (size == 0)
		return; // Eğer sıralanacak eleman yoksa, işlem yapmadan çıkar.
	if (size == 1)
	{
		pa(s, 1); // Stack B'den Stack A'ya taşır.
		return;
	}
	if (size == 2)
	{
		if (s->b && s->b->next && s->b->index < s->b->next->index)
			sb(&s->b, 1); // Eğer sıralı değilse, swap işlemi yapar.
		pa(s, 1);		  // Stack B'den Stack A'ya taşır.
		pa(s, 1);		  // Stack B'den Stack A'ya taşır.
		return;
	}
	sort_small_b_three(s); // 3 eleman için özel sıralama.
}

void sort_small_b_three(t_stack *s)
{
	// Stack B'deki 3 elemanı sıralar.
	if (s->b->index >= s->b->next->index && s->b->index >= s->b->next->next->index)
		pa(s, 1); // En büyük elemanı Stack A'ya taşır.
	else if (s->b->next->index >= s->b->index && s->b->next->index >= s->b->next->next->index)
	{
		sb(&s->b, 1); // İlk iki elemanı değiştirir.
		pa(s, 1);	  // En büyük elemanı Stack A'ya taşır.
	}
	else
	{
		rb(&s->b, 1);  // Stack B'yi döndürür.
		sb(&s->b, 1);  // İlk iki elemanı değiştirir.
		pa(s, 1);	   // En büyük elemanı Stack A'ya taşır.
		rrb(&s->b, 1); // Stack B'yi ters döndürür.
	}
	if (s->b && s->b->next && s->b->index < s->b->next->index)
		sb(&s->b, 1); // Eğer sıralı değilse, swap işlemi yapar.
	pa(s, 1);
	pa(s, 1);
}
