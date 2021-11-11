/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:01:14 by lraffin           #+#    #+#             */
/*   Updated: 2021/11/11 17:47:37 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, int start, int len)
{
	char	*d;
	int		i;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		d = malloc(sizeof(char) * (ft_strlen(s) + 1));
	else
		d = malloc(sizeof(char) * (len + 1));
	if (!d)
		return (NULL);
	i = 0;
	if (start < ft_strlen(s))
	{
		while (s[start + i] && i < len)
		{
			d[i] = s[start + i];
			i++;
		}
		d[i] = 0;
	}
	else
		d[0] = 0;
	return (d);
}
