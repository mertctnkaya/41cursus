/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 10:00:00 by mecetink          #+#    #+#             */
/*   Updated: 2025/11/02 10:00:00 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	free_stack(t_node *stack)
{
	t_node	*temp;

 	if (!stack)
 		return ;
 	while (stack)
 	{
 		temp = stack->next;
 		free(stack);
 		stack = temp;
 	}
}

void	raise_error(t_node *a, t_node *b)
{
 	write(2, "Error\n", 6);
 	if (a)
 		free_stack(a);
 	if (b)
 		free_stack(b);
 	exit(1);
}
