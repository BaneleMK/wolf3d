/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeintarray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmkhize <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:33:48 by bmkhize           #+#    #+#             */
/*   Updated: 2018/08/27 14:34:36 by bmkhize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freeintarray(int **str, int elem_count)
{
	int y;

	y = 0;
	if (str)
	{
		while (y < elem_count)
		{
			free(str[y]);
			y++;
		}
		free(str);
	}
}
