/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:31:06 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/28 12:56:33 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
int		is_sorted(t_node *node);
long	atol_check(const char *str, t_node *a);
int		match_case(t_node *a, int *n);
int		do_operations(t_stack *s, int op);

t_node	*parse_and_create_stack(int argc, char **argv, int *size);
void	assign_index(t_node **node, int size);
t_node	*new_item(int num);

void	chunking_sort(t_stack *s);
void	restore_by_max(t_stack *s);
void	restore_final_sort(t_stack *s);

void	sort_3(t_node **a);

void	sort_4(t_stack *s);
void	sort_5(t_stack *s);

void	sa(t_node **a, int cout);
void	sb(t_node **b, int cout);

void	pa(t_stack *s, int cout);
void	pb(t_stack *s, int cout);

void	ra(t_node **a, int cout);
void	rb(t_node **b, int cout);

void	rra(t_node **a, int cout);
void	rrb(t_node **b, int cout);



#endif