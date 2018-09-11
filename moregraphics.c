/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moregraphics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmkhize <bmkhize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 16:44:19 by bmkhize           #+#    #+#             */
/*   Updated: 2018/09/11 16:47:01 by bmkhize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	make_skyandground(t_raycast *ray, t_sdl *sdl)
{
	if (ray->x == -1)
	{
		sdl->skybox.x = 0;
		sdl->skybox.y = 0;
		sdl->skybox.w = WIN_W;
		sdl->skybox.h = ray->height / 2;
		sdl->ground.x = 0;
		sdl->ground.y = ray->height / 2;
		sdl->ground.w = WIN_W;
		sdl->ground.h = ray->height / 2;
	}
	SDL_SetRenderDrawColor(sdl->renderer, 20, 20, 55, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(sdl->renderer, &sdl->skybox);
	SDL_SetRenderDrawColor(sdl->renderer, 50, 50, 50, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(sdl->renderer, &sdl->ground);
}

int		make_int_array(t_raycast *ray, t_array *newl)
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

void	lighting(t_raycast *ray, t_move *move)
{
	if (ray->side == 1)
	{
		if (ray->sidedistx > move->light_val)
			ray->sidedistx = move->light_val;
		else if (ray->sidedistx < 1)
			ray->sidedistx = 1;
	}
	else
	{
		if (ray->sidedisty > move->light_val)
			ray->sidedisty = move->light_val;
		else if (ray->sidedisty < 1)
			ray->sidedisty = 1;
	}
}

void	mini_map(t_raycast *ray)
{
	int x;
	int y;

	y = 0;
	ft_putendl("L = lighting | M = MINI_MAP :");
	while (y < ray->maph)
	{
		x = 0;
		while (x < ray->mapw)
		{
			if (y == (int)(ray->posy))
			{
				if (x == (int)(ray->posx))
					ft_putstr("🐺");
				else
					(ray->map[y][x]) != 0 ? ft_putchar('#') : ft_putchar('.');
			}
			else
				(ray->map[y][x]) != 0 ? ft_putchar('#') : ft_putchar('.');
			ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
