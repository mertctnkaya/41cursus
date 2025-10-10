/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 20:44:04 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/07 22:32:06 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void ra(t_item **a, int cout)
{
	t_item *head;
	t_item *tail;

	if (!*a || !(*a)->next)
		return;
	head = *a;
	tail = *a;
	while (tail->next)
		tail = tail->next;
	*a = head->next;
	(*a)->prev = NULL;
	tail->next = head;
	head->prev = tail;
	head->next = NULL;
	if (cout)
		write(1, "ra\n", 3);
}

void rb(t_item **b, int cout)
{
	t_item *head;
	t_item *tail;

	if (!*b || !(*b)->next)
		return;
	head = *b;
	tail = *b;
	while (tail->next)
		tail = tail->next;
	*b = head->next;
	(*b)->prev = NULL;
	tail->next = head;
	head->prev = tail;
	head->next = NULL;
	if (cout)
		write(1, "rb\n", 3);
}

void rr(t_item **a, t_item **b, int cout)
{
	if (!*a || !(*a)->next || !*b || !(*b)->next)
		return;
	ra(a, 0);
	rb(b, 0);
	if (cout)
		write(1, "rr\n", 3);
}
