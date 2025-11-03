/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:48:24 by mecetink          #+#    #+#             */
/*   Updated: 2025/11/03 16:38:42 by mecetink         ###   ########.fr       */
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

static void	push_swap(t_stack *s)
{
	if (s->total_size <= 1)
		return ;
	if (s->total_size == 2)
		sa(&s->a, 1);
	else if (s->total_size == 3)
		sort_3(&s->a);
	else if (s->total_size <= 5)
		sort_5(s);
	else
		chunking_sort(s);
}

int	main(int argc, char **argv)
{
	t_stack	s;

	if (argc <= 2)
		exit(1);
	s.a = parse_and_create_stack(argc, argv, &s.total_size);
	s.b = NULL;
	s.size_a = s.total_size;
	s.size_b = 0;
	assign_index(&s.a, s.total_size);
	if (is_sorted(s.a))
	{
		free_stack(s.a);
		exit(1);
	}
	push_swap(&s);
	free_stack(s.a);
	free_stack(s.b);
	return (0);
}
