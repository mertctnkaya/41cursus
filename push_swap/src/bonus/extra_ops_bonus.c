/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_ops_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 13:42:14 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/28 13:06:09 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker_bonus.h"

void	ss(t_item **a, t_item **b, int cout)
{
	sa(a, 0);
	sb(b, 0);
	if (cout)
		write(1, "ss\n", 3);
}

void	rr(t_item **a, t_item **b, int cout)
{
	ra(a, 0);
	rb(b, 0);
	if (cout)
		write(1, "rr\n", 3);
}

void	rrr(t_item **a, t_item **b, int cout)
{
	rra(a, 0);
	rrb(b, 0);
	if (cout)
		write(1, "rrr\n", 4);
}
