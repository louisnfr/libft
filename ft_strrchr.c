/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 14:39:50 by lraffin           #+#    #+#             */
/*   Updated: 2021/11/11 17:52:00 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i != 0)
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i--;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}
