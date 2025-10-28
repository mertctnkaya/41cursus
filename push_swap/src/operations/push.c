/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 22:32:11 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/28 13:15:10 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	pa(t_stack *s, int cout)
{
	t_item	*temp;

	if (!s->b)
		return ;
	temp = s->b;
	s->b = s->b->next;
	if (s->b)
		s->b->prev = NULL;
	temp->next = s->a;
	if (s->a)
		s->a->prev = temp;
	s->a = temp;
	s->size_a++;
	s->size_b--;
	if (cout)
		write(1, "pa\n", 3);
}

void	pb(t_stack *s, int cout)
{
	t_item	*temp;

	if (!s->a)
		return ;
	temp = s->a;
	s->a = s->a->next;
	if (s->a)
		s->a->prev = NULL;
	temp->next = s->b;
	if (s->b)
		s->b->prev = temp;
	s->b = temp;
	s->size_a--;
	s->size_b++;
	if (cout)
		write(1, "pb\n", 3);
}
