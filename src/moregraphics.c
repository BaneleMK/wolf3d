/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moregraphics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmkhize <bmkhize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 16:44:19 by bmkhize           #+#    #+#             */
/*   Updated: 2018/09/15 14:39:16 by bmkhize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	fastmake_skyandground(t_raycast *ray, t_sdl *sdl)
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
	SDL_SetRenderDrawColor(sdl->renderer, 50, 50, 70, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(sdl->renderer, &sdl->ground);
}

void	make_skyandground(t_raycast *ray, t_sdl *sdl, t_dda *dda)
{
	dda->x1 = 0;
	dda->y1 = 0;
	dda->x2 = WIN_W;
	dda->y2 = dda->y1;
	SDL_SetRenderDrawColor(sdl->renderer, 20, 20, 55, SDL_ALPHA_OPAQUE);
	while (dda->y1 < ray->height / 2)
	{
		drawdda(dda, sdl);
		dda->y1++;
		dda->y2 = dda->y1;
	}
	SDL_SetRenderDrawColor(sdl->renderer, 70, 50, 50, SDL_ALPHA_OPAQUE);
	while (dda->y1 < WIN_H)
	{
		drawdda(dda, sdl);
		dda->y1++;
		dda->y2 = dda->y1;
	}
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
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

void	drawdda(t_dda *d, t_sdl *sdl)
{
	d->dx = d->x2 - d->x1;
	d->dy = (d->y2 - d->y1);
	if (fabs(d->dx) >= fabs(d->dy))
		d->step = fabs(d->dx);
	else
		d->step = fabs(d->dy);
	d->dx = d->dx / d->step;
	d->dy = d->dy / d->step;
	d->x = d->x1;
	d->y = d->y1;
	d->i = 0;
	while (d->i <= d->step && ++d->i)
	{
		SDL_RenderDrawPoint(sdl->renderer, d->x, d->y);
		d->x += d->dx;
		d->y += d->dy;
	}
}
