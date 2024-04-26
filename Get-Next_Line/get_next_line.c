/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 02:11:18 by soel-mou          #+#    #+#             */
/*   Updated: 2024/03/06 02:11:54 by soel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_new_line(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

static char	*current_buffer(int fd, char *curr_bff, int *read_byt)
{
	*read_byt = read(fd, curr_bff, BUFFER_SIZE);
	if (*read_byt < 0)
	{
		free(curr_bff);
		return (NULL);
	}
	curr_bff[*read_byt] = '\0';
	return (curr_bff);
}

static char	*joinline(int fd, char **line, int *read_byt)
{
	char	*curr_bff;
	char	*tail;

	tail = NULL;
	curr_bff = malloc(BUFFER_SIZE + 1);
	if (!curr_bff)
		return (NULL);
	curr_bff = current_buffer(fd, curr_bff, read_byt);
	*line = ft_strjoin(*line, curr_bff, 1, 0);
	while (*read_byt > 0 && !find_new_line(curr_bff))
	{
		curr_bff = current_buffer(fd, curr_bff, read_byt);
		*line = ft_strjoin(*line, curr_bff, 1, 0);
	}
	if (find_new_line(*line))
	{
		tail = after_nl(*line);
		*line = ft_strjoin(NULL, until_nl(*line), 0, 1);
	}
	free(curr_bff);
	return (tail);
}

char	*get_next_line(int fd)
{
	static char	*tail;
	int			read_byt;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (0);
	line = ft_strjoin("", "", 0, 0);
	if (tail)
	{
		line = ft_strjoin(tail, line, 0, 1);
		if (tail)
			free(tail);
		tail = NULL;
	}
	tail = joinline(fd, &line, &read_byt);
	if (line[0] == '\0' || read_byt < 0)
		return (free(line), free(tail), tail = NULL, NULL);
	return (line);
}
