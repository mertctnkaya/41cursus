/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 20:44:17 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/17 01:58:39 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// Stack'lerde ters döndürme işlemleri için kullanılan fonksiyonlar içerir.

void rra(t_item **a, int cout)
{
	// Stack A'nın tüm elemanlarını bir kez ters döndürür (reverse rotate).
	t_item *head;
	t_item *tail;

	if (!*a || !(*a)->next)
		return; // Eğer Stack A boşsa veya tek eleman varsa, işlem yapmadan çıkar.
	head = *a;	// Stack A'nın ilk elemanını tutar.
	tail = *a;	// Stack A'nın son elemanını bulmak için kullanılır.
	while (tail->next)
		tail = tail->next; // Stack A'nın sonuna kadar ilerler.

	tail->prev->next = NULL; // Stack A'nın sondan bir önceki elemanını son eleman yapar.
	tail->prev = NULL;		 // Eski son elemanın önceki işaretçisini NULL yapar.
	tail->next = head;		 // Eski son elemanı Stack A'nın başına ekler.
	head->prev = tail;		 // Eski baş elemanın önceki işaretçisini günceller.
	*a = tail;				 // Stack A'nın başını günceller.
	if (cout)
		write(1, "rra\n", 4); // Eğer cout aktifse, "rra" komutunu yazdırır.
}

void rrb(t_item **b, int cout)
{
	// Stack B'nin tüm elemanlarını bir kez ters döndürür (reverse rotate).
	t_item *head;
	t_item *tail;

	if (!*b || !(*b)->next)
		return; // Eğer Stack B boşsa veya tek eleman varsa, işlem yapmadan çıkar.
	head = *b;	// Stack B'nin ilk elemanını tutar.
	tail = *b;	// Stack B'nin son elemanını bulmak için kullanılır.
	while (tail->next)
		tail = tail->next; // Stack B'nin sonuna kadar ilerler.

	tail->prev->next = NULL; // Stack B'nin sondan bir önceki elemanını son eleman yapar.
	tail->prev = NULL;		 // Eski son elemanın önceki işaretçisini NULL yapar.
	tail->next = head;		 // Eski son elemanı Stack B'nin başına ekler.
	head->prev = tail;		 // Eski baş elemanın önceki işaretçisini günceller.
	*b = tail;				 // Stack B'nin başını günceller.
	if (cout)
		write(1, "rrb\n", 4); // Eğer cout aktifse, "rrb" komutunu yazdırır.
}
