/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 20:44:04 by mecetink          #+#    #+#             */
/*   Updated: 2025/09/22 21:17:09 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// ra (rotate a): Yığın a'nın tüm elemanlarını 1 yukarı kaydırır.
void	ra(t_node **a, int print)
{
	t_node	*head;
	t_node	*tail;

	if (!*a || !(*a)->next)
		return ;
	head = *a;
	tail = *a;
	while (tail->next)
		tail = tail->next;
	*a = head->next;
	(*a)->prev = NULL;
	tail->next = head;
	head->prev = tail;
	head->next = NULL;
	if (print)
		write(1, "ra\n", 3);
}

// rb (rotate b): Yığın b'nin tüm elemanlarını 1 yukarı kaydırır.
void	rb(t_node **b, int print)
{
	t_node	*head;
	t_node	*tail;

	if (!*b || !(*b)->next)
		return ;
	head = *b;
	tail = *b;
	while (tail->next)
		tail = tail->next;
	*b = head->next;
	(*b)->prev = NULL;
	tail->next = head;
	head->prev = tail;
	head->next = NULL;
	if (print)
		write(1, "rb\n", 3);
}

// rr: ra ve rb'yi aynı anda yapar.
void	rr(t_node **a, t_node **b, int print)
{
	if (!*a || !(*a)->next || !*b || !(*b)->next)
		return ;
	ra(a, 0);
	rb(b, 0);
	if (print)
		write(1, "rr\n", 3);
}
