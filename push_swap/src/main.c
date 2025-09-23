/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:48:24 by mecetink          #+#    #+#             */
/*   Updated: 2025/09/23 15:16:55 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

// Yığın belleğini temizler.
void free_stack(t_node *stack)
{
	t_node *temp;

	if (!stack)
		return;
	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

// Yığının zaten sıralanmış olup olmadığını kontrol eder.
int is_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		// Indexleri kontrol etmek, 'value'ları kontrol etmekten daha güvenlidir
		if (stack->index > stack->next->index)
			return (0); // Sıralanmamış
		stack = stack->next;
	}
	return (1); // Sıralanmış
}

int main(int argc, char **argv)
{
	t_stack s;

	// Argüman yoksa başarılı bir şekilde çıkar[cite: 196].
	if (argc == 1)
		return (0);

	// Yığınları başlatma
	s.a = parse_and_create_stack(argc, argv, &s.total_size);
	s.b = NULL;
	s.size_a = s.total_size;
	s.size_b = 0;

	// Index atama (performans optimizasyonu)
	assign_index(&s.a, s.total_size);

	// Zaten sıralanmışsa çık
	if (is_sorted(s.a))
	{
		free_stack(s.a);
		return (0);
	}

	// Sıralama Algoritmasını başlatma (low-count ve large-count ayrımı burada yapılacak)
	push_swap(&s);

	// Belleği temizleme
	free_stack(s.a);
	free_stack(s.b);

	return (0);
}