/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banelord <banelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:10:47 by bmkhize           #+#    #+#             */
/*   Updated: 2018/09/13 00:29:22 by banelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#define COLOUR SDL_SetRenderDrawColor
#define SDY ray->sidedisty
#define SDX ray->sidedistx

void	update_map_info(t_raycast *ray)
{
	ray->camera_x = 2 * ray->x / (double)WIN_W - 1;
	ray->raydirx = ray->dirx + ray->planex * ray->camera_x;
	ray->raydiry = ray->diry + ray->planey * ray->camera_x;
	ray->mapx = (int)ray->posx;
	ray->mapy = (int)ray->posy;
	ray->deltadistx = fabs(1 / ray->raydirx);
	ray->deltadisty = fabs(1 / ray->raydiry);
}

void	side_dist(t_raycast *ray)
{
	if (ray->raydirx > 0)
	{
		ray->sidedistx = (ray->mapx - ray->posx + 1) * ray->deltadistx;
		ray->stepx = 1;
	}
	else
	{
		ray->sidedistx = (-ray->mapx + ray->posx) * ray->deltadistx;
		ray->stepx = -1;
	}
	if (ray->raydiry > 0)
	{
		ray->sidedisty = (ray->mapy - ray->posy + 1) * ray->deltadisty;
		ray->stepy = 1;
	}
	else
	{
		ray->sidedisty = (-ray->mapy + ray->posy) * ray->deltadisty;
		ray->stepy = -1;
	}
}

void	wall_detect(t_raycast *ray)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->sidedistx > ray->sidedisty)
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
			ray->side = 0;
		}
		else
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
			ray->side = 1;
		}
		if (ray->map[ray->mapy][ray->mapx] > 0)
			ray->hit = 1;
	}
}

void	wall_height(t_raycast *ray)
{
	if (ray->side == 1)
		ray->parallelwalldst = (ray->mapx - ray->posx + \
		(1 - ray->stepx) / 2) / ray->raydirx;
	else
		ray->parallelwalldst = (ray->mapy - ray->posy + \
		(1 - ray->stepy) / 2) / ray->raydiry;
	ray->wallheight = (int)((ray->height) / ray->parallelwalldst);
	ray->wall_start = -ray->wallheight / 2 + ray->height / 2;
	if (ray->wall_start < 0)
		ray->wall_start = 0;
	ray->wall_end = ray->wallheight / 2 + ray->height / 2;
	if (ray->wall_end >= ray->height)
		ray->wall_end = ray->height - 1;
}

void	colour_picker(t_raycast *ray, t_sdl *sdl, t_move *move)
{
	if (move->lighting != 1)
	{
		SDX = 1;
		SDY = 1;
	}
	else
		lighting(ray, move);
	if (ray->side == 1)
	{
		if (ray->raydirx < 0)
			COLOUR(sdl->renderer, 255 / SDX, 0, 0, SDL_ALPHA_OPAQUE);
		else
			COLOUR(sdl->renderer, 255 / SDX, 255 / SDX, 0, SDL_ALPHA_OPAQUE);
	}
	else
	{
		if (ray->raydiry < 0)
			COLOUR(sdl->renderer, 0, 255 / SDY, 0, SDL_ALPHA_OPAQUE);
		else
			COLOUR(sdl->renderer, 0, 0, 255 / SDY, SDL_ALPHA_OPAQUE);
	}
	drawmethod(ray, sdl);
	ray->x++;
}
