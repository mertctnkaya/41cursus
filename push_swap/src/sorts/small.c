/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 20:52:49 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/17 01:52:06 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// Küçük boyutlu sıralama işlemleri için fonksiyonlar içerir.

void sort_2(t_item **a)
{
	// 2 elemanlı bir stack'i sıralar.
	if (!is_sorted(*a))
		sa(a, 1); // Eğer sıralı değilse, swap işlemi yapar.
}

void sort_3(t_item **a)
{
	// 3 elemanlı bir stack'i sıralar.
	int top;
	int mid;
	int bot;

	if (is_sorted(*a))
		return;					   // Eğer sıralıysa, işlem yapmadan çıkar.
	top = (*a)->index;			   // İlk elemanın index'i.
	mid = (*a)->next->index;	   // İkinci elemanın index'i.
	bot = (*a)->next->next->index; // Üçüncü elemanın index'i.
	if (top < mid && mid > bot && top < bot)
	{
		rra(a, 1); // Reverse rotate işlemi.
		sa(a, 1);  // Swap işlemi.
	}
	else if (top > mid && mid < bot && top < bot)
		sa(a, 1); // Sadece swap işlemi.
	else if (top < mid && mid > bot && top > bot)
		rra(a, 1); // Sadece reverse rotate işlemi.
	else if (top > mid && mid < bot && top > bot)
		ra(a, 1); // Rotate işlemi.
	else if (top > mid && mid > bot)
	{
		sa(a, 1);  // Swap işlemi.
		rra(a, 1); // Reverse rotate işlemi.
	}
}
