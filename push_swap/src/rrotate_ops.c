/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 20:44:17 by mecetink          #+#    #+#             */
/*   Updated: 2025/09/22 21:17:17 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// rra (reverse rotate a): Yığın a'nın tüm elemanlarını 1 aşağı kaydırır.
void rra(t_node **a, int print)
{
	t_node *head;
	t_node *tail;

	if (!*a || !(*a)->next)
		return;
	head = *a;
	tail = *a;
	while (tail->next)
		tail = tail->next;
	tail->prev->next = NULL;
	tail->prev = NULL;
	tail->next = head;
	head->prev = tail;
	*a = tail;
	if (print)
		write(1, "rra\n", 4);
}

// rrb (reverse rotate b): Yığın b'nin tüm elemanlarını 1 aşağı kaydırır.
void rrb(t_node **b, int print)
{
	t_node *head;
	t_node *tail;

	if (!*b || !(*b)->next)
		return;
	head = *b;
	tail = *b;
	while (tail->next)
		tail = tail->next;
	tail->prev->next = NULL;
	tail->prev = NULL;
	tail->next = head;
	head->prev = tail;
	*b = tail;
	if (print)
		write(1, "rrb\n", 4);
}

// rrr: rra ve rrb'yi aynı anda yapar.
void rrr(t_node **a, t_node **b, int print)
{
	if (!*a || !(*a)->next || !*b || !(*b)->next)
		return;
	rra(a, 0);
	rrb(b, 0);
	if (print)
		write(1, "rrr\n", 4);
}
