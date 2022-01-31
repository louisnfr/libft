/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_comma.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 22:08:45 by lraffin           #+#    #+#             */
/*   Updated: 2022/01/31 22:08:52 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit_comma(int c, int *commas)
{
	if ((c >= 48 && c <= 57) || c == ',')
	{
		if (c == ',')
			(*commas)++;
		return (SUCCESS);
	}
	return (FAILURE);
}
