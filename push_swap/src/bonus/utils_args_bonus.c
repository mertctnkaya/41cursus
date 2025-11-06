/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:38:29 by mecetink          #+#    #+#             */
/*   Updated: 2025/11/06 13:39:49 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker_bonus.h"

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

void	parse_and_add(char *str_num, t_node **a, t_node **current,
							int *size, char **split_arr)
{
	long	num;
	t_node	*new;

	num = atol_check(str_num, *a, split_arr);
	check_duplicates((int)num, *a, split_arr);
	new = new_item((int)num, *a, split_arr);
	append_item(a, current, new);
	(*size)++;
}

void	parse_split_and_add(char **split_arr, t_node **a, t_node **current,
						int *size)
{
	int i;

	i = 0;
	if (!split_arr)
		return ;
	while (split_arr[i])
		parse_and_add(split_arr[i++], a, current, size, split_arr);
}

void	free_split_arr(char **split_arr)
{
	int i = 0;

	if (!split_arr)
		return ;
	while (split_arr[i])
	{
		free(split_arr[i]);
		i++;
	}
	free(split_arr);
}
