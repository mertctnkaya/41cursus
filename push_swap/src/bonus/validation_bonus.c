/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:47:55 by mecetink          #+#    #+#             */
/*   Updated: 2025/11/07 15:12:22 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker_bonus.h"
#include "../../../libft/libft.h"

t_node	*new_item(int num, t_node *a, char **split_arr)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		raise_error(a, 0, split_arr);
	new->prev = 0;
	new->next = 0;
	new->index = -1;
	new->value = num;
	return (new);
}

void	check_duplicates(int value, t_node *a, char **split_arr)
{
	t_node	*current;

	current = a;
	while (current)
	{
		if (current->value == value)
			raise_error(a, 0, split_arr);
		current = current->next;
	}
}

void	append_item(t_node **a, t_node **current, t_node *item)
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
	int		i;
	char	**split_arr;

	a = NULL;
	current = NULL;
	i = 1;
	*size = 0;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			split_arr = ft_split(argv[i], ' ');
			if (!split_arr)
				raise_error(a, 0, split_arr);
			parse_split(split_arr, &a, &current, size);
			free_split_arr(split_arr);
		}
		else
			parse_arg(argv[i], &a, &current, size);
		i++;
	}
	return (a);
}

void	assign_index(t_node **stack, int size)
{
	t_node	*cur;
	t_node	*lowest;
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
