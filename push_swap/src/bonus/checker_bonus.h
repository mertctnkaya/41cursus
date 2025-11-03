/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:03:31 by mecetink          #+#    #+#             */
/*   Updated: 2025/11/03 15:05:01 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*a;
	t_node	*b;
	int		size_a;
	int		size_b;
	int		total_size;
}	t_stack;

void	raise_error(t_node *a, t_node *b);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
long	atol_check(const char *str, t_node *a);
void	free_stack(t_node *node);

t_node	*parse_and_create_stack(int argc, char **argv, int *size);
void	assign_index(t_node **node, int size);
int		is_sorted(t_node *node);

void	sa(t_node **a, int cout);
void	sb(t_node **b, int cout);

void	pa(t_stack *s, int cout);
void	pb(t_stack *s, int cout);

void	ra(t_node **a, int cout);
void	rb(t_node **b, int cout);

void	rra(t_node **a, int cout);
void	rrb(t_node **b, int cout);

void	rrr(t_node **a, t_node **b, int cout);
void	rr(t_node **a, t_node **b, int cout);
void	ss(t_node **a, t_node **b, int cout);

#endif