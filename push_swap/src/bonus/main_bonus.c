/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:04:20 by mecetink          #+#    #+#             */
/*   Updated: 2025/11/07 14:59:32 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker_bonus.h"
#include "../../libft/libft.h"

void	free_stack(t_node *node)
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

static int	apply_operation_per_line(t_stack *s, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0 || ft_strcmp(line, "sa") == 0)
		sa(&s->a, 0);
	else if (ft_strcmp(line, "sb\n") == 0 || ft_strcmp(line, "sb") == 0)
		sb(&s->b, 0);
	else if (ft_strcmp(line, "ss\n") == 0 || ft_strcmp(line, "ss") == 0)
		ss(&s->a, &s->b, 0);
	else if (ft_strcmp(line, "pa\n") == 0 || ft_strcmp(line, "pa") == 0)
		pa(s, 0);
	else if (ft_strcmp(line, "pb\n") == 0 || ft_strcmp(line, "pb") == 0)
		pb(s, 0);
	else if (ft_strcmp(line, "ra\n") == 0 || ft_strcmp(line, "ra") == 0)
		ra(&s->a, 0);
	else if (ft_strcmp(line, "rb\n") == 0 || ft_strcmp(line, "rb") == 0)
		rb(&s->b, 0);
	else if (ft_strcmp(line, "rr\n") == 0 || ft_strcmp(line, "rr") == 0)
		rr(&s->a, &s->b, 0);
	else if (ft_strcmp(line, "rra\n") == 0 || ft_strcmp(line, "rra") == 0)
		rra(&s->a, 0);
	else if (ft_strcmp(line, "rrb\n") == 0 || ft_strcmp(line, "rrb") == 0)
		rrb(&s->b, 0);
	else if (ft_strcmp(line, "rrr\n") == 0 || ft_strcmp(line, "rrr") == 0)
		rrr(&s->a, &s->b, 0);
	else
		return (0);
	return (1);
}

static char	*read_line_stdin(void)
{
	char	buf[5];
	char	c;
	char	*out;
	int		len;

	len = 0;
	while (len < 4 && (read(0, &c, 1)) > 0)
	{
		buf[len++] = c;
		if (c == '\n')
			break ;
	}
	if (len == 0)
		return (NULL);
	out = malloc(len + 1);
	if (!out)
		return (NULL);
	ft_memcpy(out, buf, len);
	out[len] = '\0';
	return (out);
}

static int	check_lines(t_stack s)
{
	char	*line;

	line = read_line_stdin();
	while (line != NULL)
	{
		if (!apply_operation_per_line(&s, line))
		{
			free(line);
			raise_error(s.a, s.b, 0);
		}
		free(line);
		line = read_line_stdin();
	}
	return (1);
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
	if (check_lines(s) <= 0)
		exit(1);
	if (is_sorted(s.a) && s.size_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(s.a);
	free_stack(s.b);
	return (0);
}
