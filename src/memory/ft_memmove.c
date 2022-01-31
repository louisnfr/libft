/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:49:34 by lraffin           #+#    #+#             */
/*   Updated: 2021/11/11 17:50:35 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, int len)
{
	unsigned char	*d;
	unsigned char	*s;
	int				i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = -1;
	if (d > s)
		while (++i < len)
			d[len - i - 1] = s[len - i - 1];
	else
		ft_memcpy(d, s, len);
	return (d);
}
