/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 00:29:40 by lraffin           #+#    #+#             */
/*   Updated: 2021/11/11 17:51:24 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, const char *src, int dstsize)
{
	int	d_len;
	int	s_len;
	int	i;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (!dstsize || dstsize < d_len + 1)
		return (dstsize + s_len);
	i = 0;
	while (src[i] && d_len + i + 1 < dstsize)
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = 0;
	return (d_len + s_len);
}
