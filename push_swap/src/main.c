/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:48:24 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/17 01:52:06 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Programın giriş noktasıdır. Komut satırı argümanlarını alır ve push_swap algoritmasını başlatır.

static void free_stack(t_item *stack)
{
	// Bellekteki stack'i serbest bırakır.
	// stack: Serbest bırakılacak stack'in başlangıç adresi.
	t_item *temp;

	if (!stack)
		return; // Eğer stack boşsa, işlem yapmadan çıkar.
	while (stack)
	{
		temp = stack->next; // Geçici olarak bir sonraki elemanı tutar.
		free(stack);		// Mevcut elemanı serbest bırakır.
		stack = temp;		// Stack'i bir sonraki elemana ilerletir.
	}
}

static void push_swap(t_stack *s)
{
	// Stack'in boyutuna göre uygun sıralama algoritmasını çağırır.
	if (s->total_size <= 1)
		return; // Eğer sıralanacak eleman yoksa, işlem yapmadan çıkar.
	if (s->total_size == 2)
		sort_2(&s->a); // 2 eleman için özel sıralama.
	else if (s->total_size == 3)
		sort_3(&s->a); // 3 eleman için özel sıralama.
	else if (s->total_size == 4)
		sort_4(s); // 4 eleman için özel sıralama.
	else if (s->total_size == 5)
		sort_5(s); // 5 eleman için özel sıralama.
	else
		quick_sort(s); // Daha büyük boyutlar için quick sort algoritması.
}

int main(int argc, char **argv)
{
	// Programın başlangıç noktası.
	t_stack s;

	if (argc == 1)
		exit(1); // Eğer argüman yoksa, programı sonlandırır.
	s.a = parse_and_create_stack(argc, argv, &s.total_size);
	s.b = NULL;
	s.size_a = s.total_size;
	s.size_b = 0;
	assign_index(&s.a, s.total_size);
	if (is_sorted(s.a))
	{
		free_stack(s.a);
		return (0);
	}
	push_swap(&s);
	free_stack(s.a);
	free_stack(s.b);
	return (0);
}
