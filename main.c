/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmkhize <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 09:37:26 by bmkhize           #+#    #+#             */
/*   Updated: 2018/08/30 09:37:29 by bmkhize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

int		make_int_array(t_raycast *ray, t_array *newl)
{
	char	**str;

	ray->maph = 0;    
	if(!(ray->map = (int **)malloc(sizeof(int *) * (newl->no_lines))))
		return (0);
	while (newl->arrays[ray->maph])
	{
		ray->mapw = 0;
		str = ft_strsplit(newl->arrays[ray->maph], ' ');
		if(!(ray->map[ray->maph] = (int *)malloc(sizeof(int) * newl->c)))
		{
			ft_freeintarray(ray->map, ray->maph);
			return(0);
		}
		while(str[ray->mapw])
		{
			ray->map[ray->maph][ray->mapw] = ft_atoi(str[ray->mapw]);
			ray->mapw++;
		}
		ft_freearray(str, ray->maph);
		free(newl->arrays[ray->maph]);
		ray->maph++;
	}
	free(newl->arrays);
	return (1);
}

void    init_values(t_raycast *ray, t_sdl *sdl)
{
    ray->width = WIN_W;
	ray->height = WIN_H;
	ray->posx = 2;
	ray->posy = 2;
	ray->dirx = -1;
	ray->diry = 0;
	ray->x = -1;
	ray->planex = 0;
	ray->planey = 0.66;
	sdl->run = 1;
	sdl->renderer = NULL;
	sdl->window = NULL;
//	SDL_Init(SDL_INIT_EVERYTHING);
//	SDL_CreateWindowAndRenderer(WIN_W, WIN_H, 0, &sdl->window, &sdl->renderer);
}

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

void		rendermap(t_raycast *ray)
{
	int x;
	int y;

	y = 0;
	ft_putendl("MAP :");
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

void wolf3d(t_raycast *ray, t_sdl *sdl, t_move *move)
{
	if (ray->x == 0 || ray->x == -1)
	{
		SDL_SetRenderDrawColor(sdl->renderer,0, 0, 0, SDL_ALPHA_OPAQUE);
    	SDL_RenderClear(sdl->renderer);
		make_skyandground(ray, sdl);
		while (ray->x < ray->width)
		{
			update_map_info(ray);
			side_dist(ray);
			wall_detect(ray);
			wall_height(ray);
			colour_picker(ray, sdl);
		}
		move->moveSpeed = 0.15;
		move->rotSpeed = 0.25;
		SDL_RenderPresent(sdl->renderer);
		rendermap(ray);
	}
	while (SDL_PollEvent(&sdl->event))
    {
		control_movement(ray, sdl, move);
		control_rotate(ray, sdl, move);
    }
}

//int	main(void)
int	raycast(t_array *newl)
{
	t_raycast 	ray;
	t_sdl 		sdl;
	t_move		move;

	(void)sdl;
	(void)move;
	//if (!(make_int_array(&ray, newl)))
		return(0);
	ft_freeintarray(ray.map, newl->no_lines);
//	init_values(&ray, &sdl);
/*	while (sdl.run)
		wolf3d(&ray, &sdl, &move);
	SDL_DestroyWindow(sdl.window);
	SDL_Quit();*/
	return (1);
}

int		maptowolf(int fd)
{
	t_array 	newl;
	int			n;

	newl.line = NULL;
	newl.joinline = NULL;
	newl.c = -1;
	newl.no_lines = 0;
	if ((n = checknmake(&newl, fd)) != 1)
		return (n);
	//if ((n = raycast(&newl)) != 1)
	//	return (n);
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