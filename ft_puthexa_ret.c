/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_ret.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:35:40 by lraffin           #+#    #+#             */
/*   Updated: 2021/06/10 17:00:11 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_printhexa(unsigned int n, const char *base, int *count)
{
	if (n > 16)
	{
		ft_printhexa(n / 16, base, count);
		ft_printhexa(n % 16, base, count);
	}
	else
		*count += write(1, &base[n], 1);
}

int	ft_puthexa_ret(unsigned int n, const char *base)
{
	int	count;

	count = 0;
	ft_printhexa(n, base, &count);
	return (count);
}