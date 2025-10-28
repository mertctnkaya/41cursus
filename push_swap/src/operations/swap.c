/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 20:43:26 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/28 13:15:18 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sa(t_item **a, int cout)
{
	int	temp_value;
	int	temp_index;

	if (!*a || !(*a)->next)
		return ;
	temp_value = (*a)->value;
	temp_index = (*a)->index;
	(*a)->value = (*a)->next->value;
	(*a)->index = (*a)->next->index;
	(*a)->next->value = temp_value;
	(*a)->next->index = temp_index;
	if (cout)
		write(1, "sa\n", 3);
}

void	sb(t_item **b, int cout)
{
	int	temp_value;
	int	temp_index;

	if (!*b || !(*b)->next)
		return ;
	temp_value = (*b)->value;
	temp_index = (*b)->index;
	(*b)->value = (*b)->next->value;
	(*b)->index = (*b)->next->index;
	(*b)->next->value = temp_value;
	(*b)->next->index = temp_index;
	if (cout)
		write(1, "sb\n", 3);
}
