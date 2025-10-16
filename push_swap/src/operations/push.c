/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 22:32:11 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/17 01:57:01 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// Stack'ler arasında eleman taşımak için kullanılan fonksiyonlar içerir.

void pa(t_stack *s, int cout)
{
	// Stack B'den Stack A'ya bir eleman taşır.
	t_item *temp;

	if (!s->b)
		return; // Eğer Stack B boşsa, işlem yapmadan çıkar.

	temp = s->b;	   // Stack B'nin ilk elemanını geçici olarak tutar.
	s->b = s->b->next; // Stack B'nin başını bir sonraki elemana kaydırır.
	if (s->b)
		s->b->prev = NULL; // Yeni baş elemanın önceki işaretçisini NULL yapar.

	temp->next = s->a; // Taşınan elemanı Stack A'nın başına ekler.
	if (s->a)
		s->a->prev = temp; // Stack A'nın eski baş elemanının önceki işaretçisini günceller.

	s->a = temp; // Stack A'nın başını günceller.
	s->size_a++; // Stack A'nın boyutunu artırır.
	s->size_b--; // Stack B'nin boyutunu azaltır.

	if (cout)
		write(1, "pa\n", 3); // Eğer cout aktifse, "pa" komutunu yazdırır.
}

void pb(t_stack *s, int cout)
{
	// Stack A'dan Stack B'ye bir eleman taşır.
	t_item *temp;

	if (!s->a)
		return; // Eğer Stack A boşsa, işlem yapmadan çıkar.

	temp = s->a;	   // Stack A'nın ilk elemanını geçici olarak tutar.
	s->a = s->a->next; // Stack A'nın başını bir sonraki elemana kaydırır.
	if (s->a)
		s->a->prev = NULL; // Yeni baş elemanın önceki işaretçisini NULL yapar.

	temp->next = s->b; // Taşınan elemanı Stack B'nin başına ekler.
	if (s->b)
		s->b->prev = temp; // Stack B'nin eski baş elemanının önceki işaretçisini günceller.

	s->b = temp; // Stack B'nin başını günceller.
	s->size_a--; // Stack A'nın boyutunu azaltır.
	s->size_b++; // Stack B'nin boyutunu artırır.

	if (cout)
		write(1, "pb\n", 3); // Eğer cout aktifse, "pb" komutunu yazdırır.
}
