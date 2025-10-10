/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 22:32:11 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/07 22:32:12 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void pa(t_item **a, t_item **b, int cout)
{
	t_item *temp;

	if (!*b)
		return;
	temp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	temp->next = *a;
	if (*a)
		(*a)->prev = temp;
	*a = temp;
	if (cout)
		write(1, "pa\n", 3);
}

void pb(t_item **a, t_item **b, int cout)
{
	t_item *temp;

	if (!*a)
		return;
	temp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	temp->next = *b;
	if (*b)
		(*b)->prev = temp;
	*b = temp;
	if (cout)
		write(1, "pb\n", 3);
}