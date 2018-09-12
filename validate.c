/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmkhize <bmkhize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 14:22:13 by bmkhize           #+#    #+#             */
/*   Updated: 2018/09/12 16:44:32 by bmkhize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				mapvalues(t_raycast *ray, int x, int y)
{
	int			valid;

	y = 1;
	valid = 0;
	while (y < ray->maph)
	{
		x = 0;
		while (x < ray->mapw)
		{
			if (ray->map[y][x] == 0 && valid == 0)
			{
				ray->posx = x + 0.1;
				ray->posy = y + 0.1;
				valid = 1;
			}
			else if (ray->map[y][x] < 0)
				return (-1);
			x++;
		}
		y++;
	}
	if (valid == 0)
		return (-2);
	return (1);
}

int				mapisvalid(t_raycast *ray)
{
	int			ret;
	int			x;
	int			y;

	x = 0;
	y = 0;
	if ((ret = mapvalues(ray, x, y)) != 1)
		return (ret);
	x = -1;
	y = -1;
	while (++x < ray->mapw)
	{
		if (ray->map[0][x] == 0)
			return (0);
		if (ray->map[ray->maph - 1][x] == 0)
			return (0);
	}
	while (++y < ray->maph)
	{
		if (ray->map[y][0] == 0)
			return (0);
		if (ray->map[y][ray->mapw - 1] == 0)
			return (0);
	}
	return (1);
}

void			drawmethod(t_raycast *ray, t_sdl *sdl)
{
	t_dda		d;

	if (sdl->draw == 1)
		SDL_RenderDrawLine(sdl->renderer, ray->x, \
			ray->wall_start, ray->x, ray->wall_end);
	else
	{
		d.x1 = ray->x;
		d.x2 = ray->x;
		d.y1 = ray->wall_start;
		d.y2 = ray->wall_end;
		drawdda(&d, sdl);
	}
}

int				make_int_array(t_raycast *ray, t_array *newl)
{
	char	**str;

	ray->maph = 0;
	if (!(ray->map = (int **)malloc(sizeof(int *) * (newl->no_lines))))
		return (0);
	while (newl->arrays[ray->maph])
	{
		ray->mapw = 0;
		str = ft_strsplit(newl->arrays[ray->maph], ' ');
		if (!(ray->map[ray->maph] = (int *)malloc(sizeof(int) * newl->c)))
		{
			ft_freeintarray(ray->map, ray->maph);
			return (0);
		}
		while (str[ray->mapw])
		{
			ray->map[ray->maph][ray->mapw] = ft_atoi(str[ray->mapw]);
			ray->mapw++;
		}
		free(newl->arrays[ray->maph]);
		ft_freearray(str, newl->c);
		ray->maph++;
	}
	free(newl->arrays);
	return (1);
}
