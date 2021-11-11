/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 02:43:28 by lraffin           #+#    #+#             */
/*   Updated: 2021/11/11 17:49:39 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(int count, int size)
{
	void	*p;

	p = malloc(size * count);
	if (!p)
		return (NULL);
	ft_memset(p, 0, size * count);
	return (p);
}
