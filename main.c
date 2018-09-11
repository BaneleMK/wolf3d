/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmkhize <bmkhize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:23:04 by bmkhize           #+#    #+#             */
/*   Updated: 2018/09/11 16:43:42 by bmkhize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

void	init_values(t_raycast *ray, t_sdl *sdl, t_move *move)
{
	ray->width = WIN_W;
	ray->height = WIN_H;
	ray->posx = 2;
	ray->posy = 2;
	ray->dirx = -1;
	ray->diry = 0;
	ray->x = -1;
	ray->planex = 0;
	ray->planey = 0.5;
	sdl->run = 1;
	sdl->renderer = NULL;
	sdl->window = NULL;
	move->lighting = 1;
	move->mini_map = 1;
	move->light_val = 20;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_CreateWindowAndRenderer(WIN_W, WIN_H, 0, &sdl->window, &sdl->renderer);
}

void	wolf3d(t_raycast *ray, t_sdl *sdl, t_move *move)
{
	if (ray->x == 0 || ray->x == -1)
	{
		SDL_SetRenderDrawColor(sdl->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(sdl->renderer);
		make_skyandground(ray, sdl);
		while (ray->x < ray->width)
		{
			update_map_info(ray);
			side_dist(ray);
			wall_detect(ray);
			wall_height(ray);
			colour_picker(ray, sdl, move);
		}
		move->moveSpeed = 0.15;
		move->rotSpeed = 0.25;
		SDL_RenderPresent(sdl->renderer);
		if (move->mini_map == 1)
			mini_map(ray);
	}
	while (SDL_PollEvent(&sdl->event))
	{
		control_movement(ray, sdl, move);
		control_rotate(ray, sdl, move);
		misc(ray, sdl, move);
	}
}

int		raycast(t_array *newl)
{
	t_raycast	ray;
	t_sdl		sdl;
	t_move		move;

	if (!(make_int_array(&ray, newl)))
		return (0);
	init_values(&ray, &sdl, &move);
	while (sdl.run)
		wolf3d(&ray, &sdl, &move);
	SDL_DestroyWindow(sdl.window);
	SDL_Quit();
	ft_freeintarray(ray.map, newl->no_lines);
	return (1);
}

int		maptowolf(int fd)
{
	t_array		newl;
	int			n;

	newl.line = NULL;
	newl.joinline = NULL;
	newl.c = -1;
	newl.no_lines = 0;
	if ((n = checknmake(&newl, fd)) != 1)
		return (n);
	if ((n = raycast(&newl)) != 1)
		return (n);
	return (1);
}

int		main(int argc, char **argv)
{
	int fd;
	int ret;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd != -1)
		{
			if ((ret = maptowolf(fd)) == 0)
				ft_putstr("Malloc FAIL\n");
			else if (ret == -2)
				ft_putstr("Found wrong line length. Exiting.\n");
			else if (ret == -3)
				ft_putstr("File contains no data\n");
		}
		else
		{
			ft_putstr("No file ");
			ft_putendl(argv[1]);
		}
		close(fd);
	}
	else
		ft_putstr("Usage : ./wolf3d <filename> [ case_size z_size ]\n");
	return (0);
}
