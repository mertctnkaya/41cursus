/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 20:09:52 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/17 01:58:39 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

// Quick sort algoritmasının ana fonksiyonlarını içerir.

static void push_by_chunk(t_stack *s, int *target, int chunk)
{
	// Elemanları belirli bir aralıkta (chunk) stack B'ye taşır.
	if (s->a->index <= *target)
	{
		pb(s, 1);	  // Stack A'dan Stack B'ye taşır.
		rb(&s->b, 1); // Stack B'yi döndürür.
		(*target)++;  // Hedef aralığı artırır.
	}
	else if (s->a->index <= *target + chunk)
	{
		pb(s, 1);	 // Stack A'dan Stack B'ye taşır.
		(*target)++; // Hedef aralığı artırır.
	}
	else
		ra(&s->a, 1); // Stack A'yı döndürür.
}

static void quick_sort_small(t_stack *s)
{
	// Küçük boyutlu stack'ler için sıralama yapar.
	if (s->size_a == 2)
		sort_2(&s->a);
	else if (s->size_a == 3)
		sort_3(&s->a);
	else if (s->size_a == 4)
		sort_4(s);
	else if (s->size_a == 5)
		sort_5(s);
}

void quick_sort(t_stack *s)
{
	// Quick sort algoritmasını başlatır.
	int target;
	int chunk;

	if (is_sorted(s->a))
		return; // Eğer stack zaten sıralıysa, işlem yapmadan çıkar.
	if (s->size_a <= 5)
	{
		quick_sort_small(s);
		return;
	}
	if (s->total_size <= 100)
		chunk = 15; // Küçük boyutlu stack'ler için chunk boyutu.
	else
		chunk = 30; // Büyük boyutlu stack'ler için chunk boyutu.
	target = 0;		// Başlangıç hedefi sıfır olarak ayarlanır.
	while (s->size_a > 0)
		push_by_chunk(s, &target, chunk);
	restore_by_max(s);
}
