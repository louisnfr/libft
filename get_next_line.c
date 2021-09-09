/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:56:52 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/09 05:24:34 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_newline(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		if (s[i++] == 10)
			return (i);
	return (0);
}

static char	*ft_current_line(char *s)
{
	char	*d;
	size_t	len;
	size_t	i;

	len = 0;
	while (s[len] != '\n')
		len++;
	d = malloc(sizeof(char) * (len + 1));
	if (!d)
		return (NULL);
	i = -1;
	while (++i < len)
		d[i] = s[i];
	d[i] = 0;
	free(s);
	return (d);
}

static void	ft_next_line(char *s, size_t start)
{
	char	*tmp;
	size_t	i;

	tmp = s;
	i = 0;
	while (tmp[start + i])
	{
		s[i] = tmp[start + i];
		i++;
	}
	s[i] = 0;
}

int	get_next_line(int fd, char **line)
{
	static char	buf[1024][BUFFER_SIZE + 1];
	int			ret;

	if (!line || BUFFER_SIZE <= 0 || (read(fd, buf[fd], 0) == -1))
		return (-1);
	ret = 1;
	*line = ft_strdup("");
	*line = ft_strjoin(*line, buf[fd]);
	while (!ft_newline(*line) && ret > 0)
	{
		ret = read(fd, buf[fd], BUFFER_SIZE);
		buf[fd][ret] = 0;
		if (ret == 0)
			break ;
		if (ret == -1)
			return (-1);
		*line = ft_strjoin(*line, buf[fd]);
	}
	if (ft_newline(*line))
		*line = ft_current_line(*line);
	ft_next_line(buf[fd], ft_newline(buf[fd]));
	if (ret == 0)
	{
		free(line);
		return (ft_bzero(buf[fd]));
	}
	free(line);
	return (1);
}
