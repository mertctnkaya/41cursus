/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:48:24 by mecetink          #+#    #+#             */
/*   Updated: 2025/11/06 13:25:12 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if (*s == (char)c)
			return ((char *)s);
		if (*s == 0)
			break ;
		s++;
	}
	return (NULL);
}

static void	free_stack(t_node *node)
{
	t_node	*temp;

	if (!node)
		return ;
	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
}

void	raise_error(t_node *a, t_node *b, char **split_arr)
{
	int	i;

	write(2, "Error\n", 6);
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	if (split_arr)
	{
		i = 0;
		while (split_arr[i])
		{
			free(split_arr[i]);
			i++;
		}
		free(split_arr);	
	}
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

	if (argc == 1)
		return (0);
	s.a = parse_and_create_stack(argc, argv, &s.total_size);
	if (s.total_size == 1)
	{
		free_stack(s.a);
		return (0);
	}
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
