/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_double_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:21:58 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/13 18:37:10 by lraffin          ###   ########.fr       */
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
