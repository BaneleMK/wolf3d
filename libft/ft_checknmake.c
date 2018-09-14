/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checknmake.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmkhize <bmkhize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 15:11:38 by bmkhize           #+#    #+#             */
/*   Updated: 2018/09/14 15:56:30 by bmkhize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		checknmake(t_array *newl, int fd)
{
	while ((newl->ret = get_next_line(fd, &newl->line)) > 0)
	{
		if (!newl->joinline)
			newl->joinline = ft_strdup("");
		if (newl->c == -1)
			newl->c = ft_wordcount(newl->line, ' ');
		else if (newl->c != (long)ft_wordcount(newl->line, ' '))
		{
			ft_strdel(&newl->joinline);
			return (-2);
		}
		newl->joinline = ft_delmstrjoin(newl->joinline, newl->line);
		ft_strdel(&newl->line);
		newl->no_lines++;
	}
	if (newl->c == 0 || newl->ret == -1)
	{
		ft_strdel(&newl->joinline);
		return (-3);
	}
	newl->arrays = ft_strsplit(newl->joinline, '|');
	ft_strdel(&newl->joinline);
	return (1);
}
