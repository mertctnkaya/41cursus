/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 20:44:17 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/28 13:15:39 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rra(t_node **a, int cout)
{
	t_node	*head;
	t_node	*tail;

	if (!*a || !(*a)->next)
		return ;
	head = *a;
	tail = *a;
	while (tail->next)
		tail = tail->next;
	tail->prev->next = NULL;
	tail->prev = NULL;
	tail->next = head;
	head->prev = tail;
	*a = tail;
	if (cout)
		write(1, "rra\n", 4);
}

void	rrb(t_node **b, int cout)
{
	t_node	*head;
	t_node	*tail;

	if (!*b || !(*b)->next)
		return ;
	head = *b;
	tail = *b;
	while (tail->next)
		tail = tail->next;
	tail->prev->next = NULL;
	tail->prev = NULL;
	tail->next = head;
	head->prev = tail;
	*b = tail;
	if (cout)
		write(1, "rrb\n", 4);
}
