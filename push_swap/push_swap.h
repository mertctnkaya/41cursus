/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:31:06 by mecetink          #+#    #+#             */
/*   Updated: 2025/11/06 18:33:18 by mecetink         ###   ########.fr       */
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

char	*ft_strchr(const char *s, int c);
void	raise_error(t_node *a, t_node *b, char **split_arr);

char	**ft_split(const char *s, char c);
char	*ft_substr(const char *s, unsigned int start, size_t len);

void	parse_and_add_tokens(char *single, t_node **a,
					t_node **current, int *size, char **split_arr);
void	free_split_arr(char **split_arr);
int		is_sorted(t_node *node);
long	atol_check(const char *str, t_node *a, char **split_arr);

t_node	*new_item(int num, t_node *a, char **split_arr);
void	check_duplicates(int value, t_node *a, char **split_arr);
void	append_item(t_node **a, t_node **current, t_node *item);
t_node	*parse_and_create_stack(int argc, char **argv, int *size);
void	assign_index(t_node **node, int size);
						
void	chunking_sort(t_stack *s);

void	sort_3(t_node **a);
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