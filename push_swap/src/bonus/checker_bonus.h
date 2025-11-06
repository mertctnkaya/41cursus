/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:03:31 by mecetink          #+#    #+#             */
/*   Updated: 2025/11/06 13:43:07 by mecetink         ###   ########.fr       */
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

void	free_stack(t_node *node);

char	*ft_substr(const char *s, unsigned int start, size_t len);
char	**ft_split(const char *s, char c);

char	*ft_strchr(const char *s, int c);
void	parse_and_add(char *str_num, t_node **a, t_node **current,
							int *size, char **split_arr);
void	parse_split_and_add(char **split_arr, t_node **a, t_node **current,
						int *size);
void	free_split_arr(char **split_arr);

void	raise_error(t_node *a, t_node *b, char **split_arr);
int		is_sorted(t_node *node);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
long	atol_check(const char *str, t_node *a, char **split_arr);

t_node	*new_item(int num, t_node *a, char **split_arr);
void	check_duplicates(int value, t_node *a, char **split_arr);
void	append_item(t_node **a, t_node **current, t_node *item);
t_node	*parse_and_create_stack(int argc, char **argv, int *size);
void	assign_index(t_node **node, int size);


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