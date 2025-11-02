/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:47:55 by mecetink          #+#    #+#             */
/*   Updated: 2025/11/02 16:09:35 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker_bonus.h"

static t_node	*new_item(int num)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		raise_error(0, 0);
	new->prev = 0;
	new->next = 0;
	new->index = -1;
	new->value = num;
	return (new);
}

static void	check_duplicates(t_node *node, int value)
{
	t_node	*current;

	current = node;
	while (current)
	{
		if (current->value == value)
			raise_error(node, 0);
		current = current->next;
	}
}

static void	append_item(t_node **a, t_node **current, t_node *item)
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

t_node	*parse_and_create_stack(int argc, char **argv, int *size)
{
	t_node	*a;
	t_node	*current;
	t_node	*new;
	long	num;
	int		i;

	a = NULL;
	current = NULL;
	i = 1;
	*size = 0;
	while (i < argc)
	{
		num = atol_check(argv[i], a);
		check_duplicates(a, (int)num);
		new = new_item((int)num);
		if (!new)
			raise_error(a, 0);
		append_item(&a, &current, new);
		(*size)++;
		i++;
	}
	return (a);
}

void	assign_index(t_node **node, int size)
{
	t_node	*cur;
	t_node	*lowest;
	int		index;

	index = 0;
	while (index < size)
	{
		lowest = NULL;
		cur = *node;
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
