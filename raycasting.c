#include "wolf3d.h"

void    update_map_info(t_raycast *ray)
{
    ray->camera_x = 2 * ray->x / (double)ray->height - 1;
	ray->raydirx = ray->dirx + ray->planex * ray->camera_x;
	ray->raydiry = ray->diry + ray->planey * ray->camera_x;
	ray->mapx = (int)ray->posx;
	ray->mapy = (int)ray->posy;
	ray->deltaDistx = fabs(1 / ray->raydirx);
	ray->deltaDisty = fabs(1 / ray->raydiry);
}

void	side_dist(t_raycast *ray)
{
	if (ray->raydirx > 0)
	{
		ray->sideDistx = (ray->mapx - ray->posx + 1) * ray->deltaDistx;
		ray->stepx = 1;
	}
	else
	{
		ray->sideDistx = (-ray->mapx + ray->posx) * ray->deltaDistx;
		ray->stepx = -1;
	}
	if (ray->raydiry > 0)
	{
		ray->sideDisty = (ray->mapy - ray->posy + 1) * ray->deltaDisty;
		ray->stepy = 1;
	}
	else
	{
		ray->sideDisty = (-ray->mapy + ray->posy) * ray->deltaDisty;
		ray->stepy = -1;
	}
}

void    wall_detect(t_raycast *ray)
{
    ray->hit = 0;
    while (ray->hit == 0)
	{
		if (ray->sideDistx > ray->sideDisty)
		{
			ray->sideDisty += ray->deltaDisty;
			ray->mapy += ray->stepy;
			ray->side = 0;
		}
		else
		{
			ray->sideDistx += ray->deltaDistx;
			ray->mapx += ray->stepx;
			ray->side = 1;
		}
		if (ray->map[ray->mapy][ray->mapx] > 0)
			ray->hit = 1;
	}
}

void    wall_height(t_raycast *ray)
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

void    colour_picker(t_raycast *ray, t_sdl *sdl)
{
    if (ray->side == 1)
	{
		if (ray->raydirx < 0)
			SDL_SetRenderDrawColor(sdl->renderer, 255 / (ray->sideDistx), 0, 0, SDL_ALPHA_OPAQUE);
		else
			SDL_SetRenderDrawColor(sdl->renderer, 255 / (ray->sideDistx), 255 / (ray->sideDistx), 0, SDL_ALPHA_OPAQUE);
	}
	else
	{
		if (ray->raydiry < 0)
			SDL_SetRenderDrawColor(sdl->renderer, 0, 255 / (ray->sideDisty), 0, SDL_ALPHA_OPAQUE);
		else
	    	SDL_SetRenderDrawColor(sdl->renderer,0, 0, 255  / (ray->sideDisty), SDL_ALPHA_OPAQUE);
	}
	SDL_RenderDrawLine(sdl->renderer, ray->x, \
        ray->wall_start, ray->x, ray->wall_end);
	ray->x++;
}