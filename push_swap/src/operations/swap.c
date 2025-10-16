/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 20:43:26 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/17 01:57:32 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// Stack'lerdeki elemanları değiştirmek için kullanılan fonksiyonlar içerir.

void sa(t_item **a, int cout)
{
	// Stack A'nın ilk iki elemanını değiştirir (swap).
	int temp_value;
	int temp_index;

	if (!*a || !(*a)->next)
		return;						 // Eğer Stack A boşsa veya tek eleman varsa, işlem yapmadan çıkar.
	temp_value = (*a)->value;		 // İlk elemanın değerini geçici olarak tutar.
	temp_index = (*a)->index;		 // İlk elemanın index'ini geçici olarak tutar.
	(*a)->value = (*a)->next->value; // İlk elemanın değerini ikinci elemanın değeriyle değiştirir.
	(*a)->index = (*a)->next->index; // İlk elemanın index'ini ikinci elemanın index'iyle değiştirir.
	(*a)->next->value = temp_value;	 // İkinci elemanın değerini geçici değerden alır.
	(*a)->next->index = temp_index;	 // İkinci elemanın index'ini geçici index'ten alır.
	if (cout)
		write(1, "sa\n", 3); // Eğer cout aktifse, "sa" komutunu yazdırır.
}

void sb(t_item **b, int cout)
{
	// Stack B'nin ilk iki elemanını değiştirir (swap).
	int temp_value;
	int temp_index;

	if (!*b || !(*b)->next)
		return;						 // Eğer Stack B boşsa veya tek eleman varsa, işlem yapmadan çıkar.
	temp_value = (*b)->value;		 // İlk elemanın değerini geçici olarak tutar.
	temp_index = (*b)->index;		 // İlk elemanın index'ini geçici olarak tutar.
	(*b)->value = (*b)->next->value; // İlk elemanın değerini ikinci elemanın değeriyle değiştirir.
	(*b)->index = (*b)->next->index; // İlk elemanın index'ini ikinci elemanın index'iyle değiştirir.
	(*b)->next->value = temp_value;	 // İkinci elemanın değerini geçici değerden alır.
	(*b)->next->index = temp_index;	 // İkinci elemanın index'ini geçici index'ten alır.
	if (cout)
		write(1, "sb\n", 3); // Eğer cout aktifse, "sb" komutunu yazdırır.
}

void ss(t_item **a, t_item **b, int cout)
{
	// Stack A ve Stack B'nin ilk iki elemanını aynı anda değiştirir (swap).
	sa(a, 0); // Stack A için swap işlemi yapar.
	sb(b, 0); // Stack B için swap işlemi yapar.
	if (cout)
		write(1, "ss\n", 3); // Eğer cout aktifse, "ss" komutunu yazdırır.
}
