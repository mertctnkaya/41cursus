/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 13:37:00 by mecetink          #+#    #+#             */
/*   Updated: 2025/11/06 21:38:01 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static void	*freeall(void *area1, void *area2, void *area3)
{
	if (area1)
		free(area1);
	if (area2)
		free(area2);
	if (area3)
		free(area3);
	return ((void *)0);
}

static char	*save_rest(char *buf)
{
	int		i;
	char	*rest;

	i = 0;
	if (!buf[i])
		return (freeall(buf, NULL, NULL));
	while (buf[i] && buf[i] != '\n')
		i++;
	rest = ft_strdup(buf + i + (buf[i] == '\n'));
	freeall(buf, NULL, NULL);
	return (rest);
}

static char	*extract_line(char *buf)
{
	char	*line;
	int		i;

	i = 0;
	if (!buf || !buf[0])
		return ((void *)0);
	while (buf[i] && buf[i] != '\n')
		i++;
	i += (buf[i] == '\n');
	line = ft_substr(buf, 0, i);
	return (line);
}

static char	*read_line(int fd, char *buf)
{
	char	*tmp;
	ssize_t	r;

	tmp = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return ((void *)0);
	if (!buf)
		buf = ft_strdup("");
	if (!buf)
		return ((void *)0);
	while (!ft_strchr(buf, '\n'))
	{
		r = read(fd, tmp, BUFFER_SIZE);
		if (r == -1)
			return (freeall(buf, tmp, NULL));
		if (r <= 0)
			break ;
		tmp[r] = 0;
		buf = ft_strjoin(buf, tmp);
		if (!buf)
			return (freeall(buf, tmp, NULL));
	}
	freeall(tmp, NULL, NULL);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return ((void *)0);
	buf = read_line(fd, buf);
	if (!buf)
		return ((void *)0);
	line = extract_line(buf);
	buf = save_rest(buf);
	return (line);
}
