/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:37:26 by mecetink          #+#    #+#             */
/*   Updated: 2025/08/06 15:20:55 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <signal.h>
# include <unistd.h>

void	write_pid(int pid);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);

#endif
