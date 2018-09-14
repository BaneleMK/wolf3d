/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmkhize <bmkhize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:33:48 by bmkhize           #+#    #+#             */
/*   Updated: 2018/09/14 11:08:59 by bmkhize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freearray(char **str, int count)
{
	int y;

	y = 0;
	if (str)
	{
		while (y < count)
		{
			free(str[y]);
			y++;
		}
		free(str);
	}
}
