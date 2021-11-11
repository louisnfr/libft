/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:21:00 by lraffin           #+#    #+#             */
/*   Updated: 2021/11/11 17:51:30 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int	srcsize;
	int	len;

	if (!dst || !src)
		return (0);
	srcsize = ft_strlen(src);
	if (dstsize)
	{
		if (srcsize >= dstsize)
			len = dstsize - 1;
		else
			len = srcsize;
		ft_memcpy(dst, src, len);
		dst[len] = 0;
	}
	return (srcsize);
}
