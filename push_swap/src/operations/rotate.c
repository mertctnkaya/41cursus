/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 20:44:04 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/17 01:58:39 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// Stack'lerde döndürme işlemleri için kullanılan fonksiyonlar içerir.

void ra(t_item **a, int cout)
{
	// Stack A'nın tüm elemanlarını bir kez döndürür (rotate).
	t_item *head;
	t_item *tail;

	if (!*a || !(*a)->next)
		return; // Eğer Stack A boşsa veya tek eleman varsa, işlem yapmadan çıkar.
	head = *a;	// Stack A'nın ilk elemanını tutar.
	tail = *a;	// Stack A'nın son elemanını bulmak için kullanılır.
	while (tail->next)
		tail = tail->next; // Stack A'nın sonuna kadar ilerler.
	*a = head->next;	   // Stack A'nın başını bir sonraki elemana kaydırır.
	(*a)->prev = NULL;	   // Yeni baş elemanın önceki işaretçisini NULL yapar.
	tail->next = head;	   // Eski baş elemanı Stack A'nın sonuna ekler.
	head->prev = tail;	   // Eski baş elemanın önceki işaretçisini günceller.
	head->next = NULL;	   // Eski baş elemanın sonraki işaretçisini NULL yapar.
	if (cout)
		write(1, "ra\n", 3); // Eğer cout aktifse, "ra" komutunu yazdırır.
}

void rb(t_item **b, int cout)
{
	// Stack B'nin tüm elemanlarını bir kez döndürür (rotate).
	t_item *head;
	t_item *tail;

	if (!*b || !(*b)->next)
		return; // Eğer Stack B boşsa veya tek eleman varsa, işlem yapmadan çıkar.
	head = *b;	// Stack B'nin ilk elemanını tutar.
	tail = *b;	// Stack B'nin son elemanını bulmak için kullanılır.
	while (tail->next)
		tail = tail->next; // Stack B'nin sonuna kadar ilerler.
	*b = head->next;	   // Stack B'nin başını bir sonraki elemana kaydırır.
	(*b)->prev = NULL;	   // Yeni baş elemanın önceki işaretçisini NULL yapar.
	tail->next = head;	   // Eski baş elemanı Stack B'nin sonuna ekler.
	head->prev = tail;	   // Eski baş elemanın önceki işaretçisini günceller.
	head->next = NULL;	   // Eski baş elemanın sonraki işaretçisini NULL yapar.
	if (cout)
		write(1, "rb\n", 3); // Eğer cout aktifse, "rb" komutunu yazdırır.
}
