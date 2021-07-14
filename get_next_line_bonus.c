/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 09:29:54 by dpeyrat           #+#    #+#             */
/*   Updated: 2020/11/30 09:29:59 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_read(int fd, char **leftover)
{
	int		ret;
	char	*buffer;
	char	*old_leftover;

	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	old_leftover = *leftover;
	if ((ret = read(fd, buffer, BUFFER_SIZE)) == -1)
	{
		free(buffer);
		return (-1);
	}
	buffer[ret] = 0;
	if (!(*leftover = ft_strjoin(*leftover, buffer)))
		return (-1);
	free(buffer);
	free(old_leftover);
	return (ret);
}

static int	ft_end_text(char **leftover, char **line)
{
	if (!(*line = ft_strdup(*leftover)))
		return (-1);
	free(*leftover);
	*leftover = 0;
	return (0);
}

static int	ft_newline_found(char **line, char *str, char **leftover)
{
	char	*temp;

	str[0] = 0;
	temp = *leftover;
	if (!(*line = ft_strdup(*leftover)))
		return (-1);
	if (!(*leftover = ft_strdup(&str[1])))
		free(temp);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	char		*str;
	static char	*leftover[OPEN_MAX];
	int			ret;

	if (fd < 0 || fd > OPEN_MAX || line == 0 || BUFFER_SIZE < 1)
		return (-1);
	if (!leftover[fd])
		if (!(leftover[fd] = ft_strdup("")))
			return (-1);
	ret = BUFFER_SIZE;
	while (42)
	{
		str = leftover[fd];
		while (*str || ret < BUFFER_SIZE)
		{
			if (*str == '\n')
				return ((ft_newline_found(line, str, &leftover[fd])));
			if (*str == 0 || ret == 0)
				return ((ft_end_text(&leftover[fd], line)));
			str++;
		}
		if ((ret = ft_read(fd, &leftover[fd])) == -1)
			return (-1);
	}
	return (-1);
}
