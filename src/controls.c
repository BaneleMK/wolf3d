/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banelord <banelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 16:17:06 by bmkhize           #+#    #+#             */
/*   Updated: 2018/09/15 00:00:16 by banelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	control_rotate(t_raycast *ray, t_sdl *sdl, t_move *move)
{
	(void)sdl;
	if (move->dir_a)
	{
		move->olddirx = ray->dirx;
		ray->dirx = ray->dirx * cos(ROT) - ray->diry * sin(ROT);
		ray->diry = move->olddirx * sin(ROT) + ray->diry * cos(ROT);
		move->oldplanex = ray->planex;
		ray->planex = ray->planex * cos(ROT) - ray->planey * sin(ROT);
		ray->planey = move->oldplanex * sin(ROT) + ray->planey * cos(ROT);
		ray->x = 0;
	}
	else if (move->dir_d)
	{
		move->olddirx = ray->dirx;
		ray->dirx = ray->dirx * cos(-ROT) - ray->diry * sin(-ROT);
		ray->diry = move->olddirx * sin(-ROT) + ray->diry * cos(-ROT);
		move->oldplanex = ray->planex;
		ray->planex = ray->planex * cos(-ROT) - ray->planey * sin(-ROT);
		ray->planey = move->oldplanex * sin(-ROT) + ray->planey * cos(-ROT);
		ray->x = 0;
	}
}

void	control_movement(t_raycast *ray, t_sdl *sdl, t_move *move)
{
	if (move->dir_w)
	{
		if (ray->map[(int)(ray->posy)][(int)(ray->posx + ray->dirx * MSP)] == 0)
			ray->posx += ray->dirx * MSP;
		if (ray->map[(int)(ray->posy + ray->diry * MSP)][(int)(ray->posx)] == 0)
			ray->posy += ray->diry * MSP;
		ray->x = 0;
	}
	else if (move->dir_s)
	{
		if (ray->map[(int)(ray->posy)][(int)(ray->posx - ray->dirx * MSP)] == 0)
			ray->posx -= ray->dirx * MSP;
		if (ray->map[(int)(ray->posy - ray->diry * MSP)][(int)(ray->posx)] == 0)
			ray->posy -= ray->diry * MSP;
		ray->x = 0;
	}
	if (sdl->event.type == SDL_QUIT || (KEYPRESSED == SDLK_ESCAPE && PRESSED))
		sdl->run = 0;
}

void	misc(t_raycast *ray, t_sdl *sdl, t_move *move)
{
	if (KEYPRESSED == SDLK_m && PRESSED)
		move->mini_map *= -1;
	else if (KEYPRESSED == SDLK_l && PRESSED)
	{
		move->lighting *= -1;
		ray->x = 0;
	}
	else if (KEYPRESSED == SDLK_MINUS && PRESSED)
	{
		if (move->light_val < 40)
		{
			move->light_val += 1;
			ray->x = 0;
		}
	}
	else if (KEYPRESSED == SDLK_EQUALS && PRESSED)
	{
		if (move->light_val > 1)
		{
			move->light_val -= 1;
			ray->x = 0;
		}
	}
	else if (KEYPRESSED == SDLK_z && PRESSED)
		sdl->draw *= -1;
}

void	control(t_raycast *ray, t_sdl *sdl, t_move *move)
{
	if (PRESSED)
	{
		if (KEYPRESSED == SDLK_a || KEYPRESSED == SDLK_LEFT)
			move->dir_a = SDL_TRUE;
		else if (KEYPRESSED == SDLK_d || KEYPRESSED == SDLK_RIGHT)
			move->dir_d = SDL_TRUE;
		else if (KEYPRESSED == SDLK_w || KEYPRESSED == SDLK_UP)
			move->dir_w = SDL_TRUE;
		else if (KEYPRESSED == SDLK_s || KEYPRESSED == SDLK_DOWN)
			move->dir_s = SDL_TRUE;
		control_movement(ray, sdl, move);
		control_rotate(ray, sdl, move);
	}
	else
	{
		if (KEYPRESSED == SDLK_a || KEYPRESSED == SDLK_LEFT)
			move->dir_a = SDL_FALSE;
		else if (KEYPRESSED == SDLK_d || KEYPRESSED == SDLK_RIGHT)
			move->dir_d = SDL_FALSE;
		else if (KEYPRESSED == SDLK_w || KEYPRESSED == SDLK_UP)
			move->dir_w = SDL_FALSE;
		else if (KEYPRESSED == SDLK_s || KEYPRESSED == SDLK_DOWN)
			move->dir_s = SDL_FALSE;
	}
	misc(ray, sdl, move);
}