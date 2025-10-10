/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:48:24 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/10 12:33:58 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	free_stack(t_item *stack)
{
	t_item	*temp;

	if (!stack)
		return ;
	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

static void	push_swap(t_stack *s)
{
	if (s->total_size <= 1)
		return ;
	if (s->total_size == 2)
		sort_2(&s->a);
	else if (s->total_size == 3)
		sort_3(&s->a);
	else if (s->total_size == 4)
		sort_4(s);
	else if (s->total_size == 5)
		sort_5(s);
	else
		quick_sort(s);
}

int	main(int argc, char **argv)
{
	t_stack	s;

	if (argc == 1)
		exit(1);
	s.a = parse_and_create_stack(argc, argv, &s.total_size);
	s.b = NULL;
	s.size_a = s.total_size;
	s.size_b = 0;
	assign_index(&s.a, s.total_size);
	if (is_sorted(s.a))
	{
		free_stack(s.a);
		return (0);
	}
	push_swap(&s);
	free_stack(s.a);
	free_stack(s.b);
	return (0);
}
