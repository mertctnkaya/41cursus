/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:03:31 by mecetink          #+#    #+#             */
/*   Updated: 2025/10/28 13:01:11 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_item
{
	int				value;
	int				index;
	struct s_item	*prev;
	struct s_item	*next;
}	t_item;

typedef struct s_stack
{
	t_item	*a;
	t_item	*b;
	int		size_a;
	int		size_b;
	int		total_size;
}	t_stack;

t_item	*parse_and_create_stack(int argc, char **argv, int *size);
void	assign_index(t_item **stack, int size);
int		is_sorted(t_item *stack);

void	raise_error(void);
long	atol_check(const char *str);
int		match_case(t_item *a, int *n);
int		do_operations(t_stack *s, int op);

void	sa(t_item **a, int cout);
void	sb(t_item **b, int cout);

void	pa(t_stack *s, int cout);
void	pb(t_stack *s, int cout);

void	ra(t_item **a, int cout);
void	rb(t_item **b, int cout);

void	rra(t_item **a, int cout);
void	rrb(t_item **b, int cout);

void	sort_2(t_item **a);
void	sort_3(t_item **a);

void	sort_4(t_stack *s);
void	sort_5(t_stack *s);

void	rrr(t_item **a, t_item **b, int cout);
void	rr(t_item **a, t_item **b, int cout);
void	ss(t_item **a, t_item **b, int cout);

void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_strcmp(const char *s1, const char *s2);

#endif