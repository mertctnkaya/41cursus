/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:31:06 by mecetink          #+#    #+#             */
/*   Updated: 2025/09/29 01:30:46 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_item
{
	int value;
	int index;
	struct s_item *prev;
	struct s_item *next;
} t_item;

typedef struct s_stack
{
	t_item *a;
	t_item *b;
	int size_a;
	int size_b;
	int total_size;
} t_stack;

t_item *parse_and_create_stack(int argc, char **argv, int *size);
void assign_index(t_item **stack, int size);
int is_sorted(t_item *stack);

void raise_error();
void free_stack(t_item *stack);
long ft_atol_check(const char *str);
int	match_case(t_item *a, int i0, int i1, int i2, int i3);
int	do_operations(t_stack *s, int op);

void sa(t_item **a, int cout);
void sb(t_item **b, int cout);
void ss(t_item **a, t_item **b, int cout);

void pa(t_item **a, t_item **b, int cout);
void pb(t_item **a, t_item **b, int cout);

void ra(t_item **a, int cout);
void rb(t_item **b, int cout);
void rr(t_item **a, t_item **b, int cout);

void rra(t_item **a, int cout);
void rrb(t_item **b, int cout);
void rrr(t_item **a, t_item **b, int cout);

void sort_2(t_item **a);
void sort_3(t_item **a);

void sort_4(t_stack *s);
void sort_5(t_stack *s);

void sort_large(t_stack *s);

void push_swap(t_stack *s);

void free_stack(t_item *stack);

#endif