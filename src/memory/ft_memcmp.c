/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 01:48:15 by lraffin           #+#    #+#             */
/*   Updated: 2021/11/11 17:50:21 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, int n)
{
	const unsigned char	*f1;
	const unsigned char	*f2;
	int					i;

	f1 = s1;
	f2 = s2;
	i = 0;
	while (i < n)
	{
		if (f1[i] != f2[i])
			return (f1[i] - f2[i]);
		i++;
	}
	return (0);
}
