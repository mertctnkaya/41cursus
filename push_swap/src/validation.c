/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:47:55 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/28 13:17:01 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_item	*new_item(int num)
{
	t_item	*new;

	new = (t_item *)malloc(sizeof(t_item));
	if (!new)
		raise_error();
	new->prev = 0;
	new->next = 0;
	new->index = -1;
	new->value = num;
	return (new);
}

static void	check_duplicates(t_item *stack, int value)
{
	t_item	*current;

	current = stack;
	while (current)
	{
		if (current->value == value)
			raise_error();
		current = current->next;
	}
}

static void	append_item(t_item **a, t_item **current, t_item *item)
{
	if (!*a)
		*a = item;
	else
	{
		(*current)->next = item;
		item->prev = *current;
	}
	*current = item;
}

t_item	*parse_and_create_stack(int argc, char **argv, int *size)
{
	t_item	*a;
	t_item	*current;
	t_item	*new;
	long	num;
	int		i;

	if (argc < 2)
		exit(0);
	a = NULL;
	current = NULL;
	i = 1;
	*size = 0;
	while (i < argc)
	{
		num = atol_check(argv[i]);
		check_duplicates(a, (int)num);
		new = new_item((int)num);
		if (!new)
			raise_error();
		append_item(&a, &current, new);
		(*size)++;
		i++;
	}
	return (a);
}

void	assign_index(t_item **stack, int size)
{
	t_item	*cur;
	t_item	*lowest;
	int		index;

	index = 0;
	while (index < size)
	{
		lowest = NULL;
		cur = *stack;
		while (cur)
		{
			if (cur->index == -1 && (!lowest || cur->value < lowest->value))
				lowest = cur;
			cur = cur->next;
		}
		if (lowest)
			lowest->index = index;
		index++;
	}
}
