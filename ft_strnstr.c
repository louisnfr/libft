/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 15:10:49 by lraffin           #+#    #+#             */
/*   Updated: 2021/11/18 23:57:33 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *haystack, char *needle, int len)
{
	int	i;
	int	j;

	if (!needle || !haystack)
		return (NULL);
	i = 0;
	while (haystack[i] && len && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < len)
		{
			j++;
			if (!needle[j])
				return (&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
