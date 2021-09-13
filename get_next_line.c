/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:56:52 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/13 21:57:05 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    clean_free(char **str)
{
    free(*str);
    *str = NULL;
}

char    *_strjoin(char *s1, char *s2)
{
    int     i;
    int     length;
    char    *dest;

    if (!s1 || !s2)
        return (NULL);
    length = ft_strlen(s1) + ft_strlen(s2);
    dest = (char *)malloc(sizeof(char) * (length + 1));
    if (!dest)
        return (NULL);
    i = -1;
    while (s1[++i])
        dest[i] = s1[i];
    while (*s2)
        dest[i++] = *s2++;
    dest[i] = '\0';
    clean_free(&s1);
    return (dest);
}

int get_next_line(int fd, char **line)
{
    char    *buffer;
    int     ret;

    buffer = (char *)malloc(sizeof(char) * 2);
    if (!buffer || !line || read(fd, buffer, 0) < 0
				|| !(*line = (char *)malloc(sizeof(char))))
    {
        clean_free(&buffer);
        return (-1);
    }
    *line[0] = '\0';
    while ((ret = read(fd, buffer, 1)) > 0)
    {
        if (buffer[0] == '\n')
            break;
        buffer[ret] = '\0';
        *line = _strjoin(*line, buffer);
    }
    clean_free(&buffer);
    return (ret);
}

// static size_t	ft_newline(char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!s)
// 		return (0);
// 	while (s[i])
// 		if (s[i++] == 10)
// 			return (i);
// 	return (0);
// }

// static char	*ft_current_line(char *s)
// {
// 	char	*d;
// 	size_t	len;
// 	size_t	i;

// 	len = 0;
// 	while (s[len] != '\n')
// 		len++;
// 	d = malloc(sizeof(char) * (len + 1));
// 	if (!d)
// 		return (NULL);
// 	i = -1;
// 	while (++i < len)
// 		d[i] = s[i];
// 	d[i] = 0;
// 	free(s);
// 	return (d);
// }

// static void	ft_next_line(char *s, size_t start)
// {
// 	char	*tmp;
// 	size_t	i;

// 	tmp = s;
// 	i = 0;
// 	while (tmp[start + i])
// 	{
// 		s[i] = tmp[start + i];
// 		i++;
// 	}
// 	s[i] = 0;
// }

// int	get_next_line(int fd, char **line)
// {
// 	static char	buf[BUFFER_SIZE + 1];
// 	int			ret;

// 	if (!line || BUFFER_SIZE <= 0 || (read(fd, buf, 0) == -1))
// 		return (-1);
// 	ret = 1;
// 	*line = ft_strdup("");
// 	*line = ft_strjoin(*line, buf);
// 	while (!ft_newline(*line) && ret > 0)
// 	{
// 		ret = read(fd, buf, BUFFER_SIZE);
// 		buf[ret] = 0;
// 		if (ret == 0)
// 			break ;
// 		if (ret == -1)
// 			return (-1);
// 		*line = ft_strjoin(*line, buf);
// 	}
// 	if (ft_newline(*line))
// 		*line = ft_current_line(*line);
// 	ft_next_line(buf, ft_newline(buf));
// 	if (ret == 0)
// 		return (ft_bzero(buf));
// 	return (1);
// }
