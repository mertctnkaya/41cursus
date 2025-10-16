/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:57:12 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/17 01:55:46 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

// quicksort_recursive.c
// Quick sort algoritmasının recursive (özyinelemeli) fonksiyonlarını içerir.

void quicksort_a(t_stack *s, int size)
{
	// Stack A'yı quick sort algoritmasıyla sıralar.
	int pivot;
	int pushed;

	if (size <= 1 || is_sorted(s->a))
		return; // Eğer sıralanacak eleman yoksa veya zaten sıralıysa, işlem yapmadan çıkar.
	if (size <= 3)
		return (sort_small_a(s, size)); // Küçük boyutlu sıralama için özel fonksiyon çağrılır.

	pivot = get_pivot(s->a, size);			   // Pivot değerini hesaplar.
	partition_a_to_b(s, pivot, size, &pushed); // Elemanları pivot'a göre böler.
	quicksort_a(s, size - pushed);			   // Pivot'un üzerindeki elemanları sıralar.
	quicksort_b(s, pushed);					   // Pivot'un altındaki elemanları sıralar.
}

void quicksort_b(t_stack *s, int size)
{
	// Stack B'yi quick sort algoritmasıyla sıralar.
	int pivot;
	int pushed;

	if (size <= 0)
		return; // Eğer sıralanacak eleman yoksa, işlem yapmadan çıkar.
	if (size <= 3)
		return (sort_small_b(s, size)); // Küçük boyutlu sıralama için özel fonksiyon çağrılır.

	pivot = get_pivot(s->b, size);			   // Pivot değerini hesaplar.
	partition_b_to_a(s, pivot, size, &pushed); // Elemanları pivot'a göre böler.
	quicksort_a(s, pushed);					   // Pivot'un üzerindeki elemanları sıralar.
	quicksort_b(s, size - pushed);			   // Pivot'un altındaki elemanları sıralar.
}
