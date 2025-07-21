/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 13:37:00 by mecetink          #+#    #+#             */
/*   Updated: 2025/07/21 17:11:21 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file get_next_line.c
 * @brief Implementation of the get_next_line function to read lines from a file descriptor.
 * This function reads from file descriptor(s) until a newline character is found or the end of the file is reached.
 * It returns the line read, including the newline character if present.
 * * The function reads data in *chunks defined by BUFFER_SIZE* and processes it to extract lines.
 * 
 * It uses a static buffer to store the remaining data between calls.
 * * A static buffer is used to keep track of the remaining data between calls to get_next_line.
 * Static datas are stored in another segment of memory, which allows to not lose the data until the program ends.
 * In assembly that segment is called .bss.
 * @return char* Pointer to the line read from the file descriptor, or NULL if an error occurs or end of file is reached.
 * @note The function assumes that the BUFFER_SIZE is defined and is greater than 0.
 */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief Frees the allocated memory for the areas provided.
 * This function takes up to three pointers and frees them if they are not NULL.
 * This function is used to reduce code lines due to Norminette rules.
 */
void	*freeall(void *area1, void *area2, void *area3)
{
	if (area1)
		free(area1);
	if (area2)
		free(area2);
	if (area3)
		free(area3);
	return ((void *)0);
}

/**
 * @brief Saves the remaining part of the buffer after extracting a line.
 * This function takes the buffer, finds the position of the newline character,
 * and creates a new string that contains everything after the newline character.
 * If there is no newline character, it frees the buffer and returns NULL.
 * @param buf The buffer containing the data read from the file descriptor.
 */
char	*save_rest(char *buf)
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

/**
 * @brief Extracts a line from the buffer up to the newline character.
 * This function scans the buffer for a newline character and creates a substring
 * that includes everything from the start of the buffer up to and including the newline character.
 * If there is no newline character, it returns the entire buffer as a string.
 * @param buf The buffer containing the data read from the file descriptor.
 * @return char* A newly allocated string containing the extracted line, or NULL if the buffer is empty or NULL.
 * @note This function allocates memory for the extracted line, which should be freed by the caller.
 */
char	*extract_line(char *buf)
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

/**
 * @brief Reads data from the file descriptor until a newline character is found or end of file is reached.
 * This function reads data in chunks defined by BUFFER_SIZE and appends it to the buffer.
 * It continues reading until a newline character is found or no more data can be read.
 * @param fd The file descriptor to read from.
 * @param buf The buffer to which the read data will be appended.
 * @return char* The updated buffer containing the read data, or NULL if an error occurs or end of file is reached.
 * @note This function allocates memory for a temporary buffer to read data from the file descriptor.
 * If an error occurs during reading, it frees the allocated memory and returns NULL.
 */
char	*read_line(int fd, char *buf)
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
	static char	*bufs[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return ((void *)0);
	bufs[fd] = read_line(fd, bufs[fd]);
	if (!bufs[fd])
		return ((void *)0);
	line = extract_line(bufs[fd]);
	bufs[fd] = save_rest(bufs[fd]);
	return (line);
}
