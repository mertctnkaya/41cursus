/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:47:55 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/17 01:52:06 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Kullanıcıdan alınan verilerin doğruluğunu kontrol eder ve stack'e ekler.

t_item *new_item(int num)
{
	// Yeni bir stack elemanı oluşturur.
	t_item *new;

	new = (t_item *)malloc(sizeof(t_item)); // Bellekten yeni bir eleman için yer ayırır.
	if (!new)
		raise_error(); // Bellek tahsisi başarısız olursa, hata verir.
	new->prev = 0;	   // Önceki eleman yok (ilk eleman için).
	new->next = 0;	   // Sonraki eleman yok (şimdilik).
	new->index = -1;   // Varsayılan index değeri.
	new->value = num;  // Elemanın değerini atar.
	return (new);	   // Yeni elemanın adresini döner.
}

static void check_duplicates(t_item *stack, int value)
{
	// Stack'te tekrar eden değer olup olmadığını kontrol eder.
	t_item *current;

	current = stack;
	while (current)
	{
		if (current->value == value)
			raise_error();		 // Eğer değer tekrar ediyorsa, hata verir.
		current = current->next; // Bir sonraki elemana geçer.
	}
}

static void append_item(t_item **a, t_item **current, t_item *item)
{
	// Yeni bir elemanı stack'e ekler.
	if (!*a)
		*a = item; // Eğer stack boşsa, yeni eleman ilk eleman olur.
	else
	{
		(*current)->next = item; // Mevcut elemanın sonrasına ekler.
		item->prev = *current;	 // Yeni elemanın önceki elemanını ayarlar.
	}
	*current = item;
}

t_item *parse_and_create_stack(int argc, char **argv, int *size)
{
	t_item *a;
	t_item *current;
	t_item *new;
	long num;
	int i;

	if (argc < 2)
		exit(0);
	a = NULL;
	current = NULL;
	i = 1;
	*size = 0;
	while (i < argc)
	{
		num = atol_check(argv[i]);
		check_duplicates(a, (int)num);
		new = new_item((int)num);
		if (!new)
			raise_error();
		append_item(&a, &current, new);
		(*size)++;
		i++;
	}
	return (a);
}

void assign_index(t_item **stack, int size)
{
	t_item *current;
	t_item *lowest;
	int index;

	index = 0;
	while (index < size)
	{
		lowest = NULL;
		current = *stack;
		while (current)
		{
			if (current->index == -1 && (!lowest || current->value < lowest->value))
				lowest = current;
			current = current->next;
		}
		if (lowest)
			lowest->index = index;
		index++;
	}
}
