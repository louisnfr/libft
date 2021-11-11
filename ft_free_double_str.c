/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_double_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:21:58 by lraffin           #+#    #+#             */
/*   Updated: 2021/11/11 17:35:41 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_double_str(char **str)
{
	int	i;

	if (!str || !*str)
		return ;
	i = -1;
	while (str && str[++i])
		clean_free(&str[i]);
	free(str);
	str = NULL;
}
