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

int map[24][24] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,2,2,2,2,2,2,2,2,2,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,2,2,2,2,0,2,2,2,2,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

int		exit_fun(int key)
{
	if (key == 12 || key == 53)
		exit(0);
	return (0);
}

/*
void	make_int_array(t_raycast *ray, t_array *newl)
{
	char	**str;

	ray->height = 0;
	ray->map = (int **)malloc(sizeof(int *) * (newl->no_lines ));
	printf("no_lines = %ld\n", newl->no_lines);
	while (newl->arrays[ray->height])
	{
		ray->width = 0;
		str = ft_strsplit(newl->arrays[ray->height], ' ');
		ray->map[newl->height] = (int *)malloc(sizeof(int) * newl->c);
		printf("\nstr %ld : %s || newl->c = %ld || newl->no_oflines %ld\n", ray->height, str[ray->width], newl->c, newl->no_lines);
		while(str[ray->width])
		{
			//printf("we in w = %ld & h = %ld str = %d\n", ray->width, ray->height, ft_atoi(str[ray->width]));
			ray->map[ray->height][ray->width] = ft_atoi(str[ray->width]);
			printf("%d ", ray->map[ray->height][ray->width]);
			ray->width++;
		}
		ft_putchar('\n');
		ft_freearray(str, newl->c);
		ft_strdel(newl->arrays);
		ray->height++;
	}
}
*/

void    init_values(t_raycast *ray, t_sdl *sdl)
{
    ray->width = WIN_W;
	ray->height = WIN_H;
	ray->posx = 13;
	ray->posy = 2;
	ray->dirx = -1;
	ray->diry = 0;
	ray->x = -1;
	ray->planex = 0;
	ray->planey = 0.66;
	sdl->run = 1;
	sdl->renderer = NULL;
	sdl->window = NULL;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_CreateWindowAndRenderer(WIN_W, WIN_H, 0, &sdl->window, &sdl->renderer);
}

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
		//delta dist x is for the euclidean distance aka real distance->
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
		if (map[ray->mapy][ray->mapx] > 0)
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
			SDL_SetRenderDrawColor(sdl->renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
		else
			SDL_SetRenderDrawColor(sdl->renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);
	}
	else
	{
		if (ray->raydiry < 0)
			SDL_SetRenderDrawColor(sdl->renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
		else
	    	SDL_SetRenderDrawColor(sdl->renderer,0, 0, 255, SDL_ALPHA_OPAQUE);
	}
	SDL_RenderDrawLine(sdl->renderer, ray->x, ray->wall_start, ray->x, ray->wall_end);
	ray->x++;
}
void    control_rotate(t_raycast *ray, t_sdl *sdl)
{

    if (sdl->event.key.keysym.sym == SDLK_a || sdl->event.key.keysym.sym == SDLK_LEFT)
    {
    	ray->olddirx = ray->dirx;
    	ray->dirx = ray->dirx * cos(ray->rotSpeed) - ray->diry * sin(ray->rotSpeed);
    	ray->diry = ray->olddirx * sin(ray->rotSpeed) + ray->diry * cos(ray->rotSpeed);
    	ray->oldplanex = ray->planex;
    	ray->planex = ray->planex * cos(ray->rotSpeed) - ray->planey * sin(ray->rotSpeed);
    	ray->planey = ray->oldplanex * sin(ray->rotSpeed) + ray->planey * cos(ray->rotSpeed);
    	SDL_SetRenderDrawColor(sdl->renderer,0, 0, 0, SDL_ALPHA_OPAQUE);
    	SDL_RenderClear(sdl->renderer);
    	ray->x = 0;
    }
    if (sdl->event.key.keysym.sym == SDLK_d || sdl->event.key.keysym.sym == SDLK_RIGHT)
    {
    	ray->olddirx = ray->dirx;
    	ray->dirx = ray->dirx * cos(-ray->rotSpeed) - ray->diry * sin(-ray->rotSpeed);
    	ray->diry = ray->olddirx * sin(-ray->rotSpeed) + ray->diry * cos(-ray->rotSpeed);
    	ray->oldplanex = ray->planex;
    	ray->planex = ray->planex * cos(-ray->rotSpeed) - ray->planey * sin(-ray->rotSpeed);
    	ray->planey = ray->oldplanex * sin(-ray->rotSpeed) + ray->planey * cos(-ray->rotSpeed);
    	SDL_SetRenderDrawColor(sdl->renderer,0, 0, 0, SDL_ALPHA_OPAQUE);
    	SDL_RenderClear(sdl->renderer);
    	ray->x = 0;
	}
}

void    control_movement(t_raycast *ray, t_sdl *sdl)
{
    if (sdl->event.key.keysym.sym == SDLK_w || sdl->event.key.keysym.sym == SDLK_UP)
	{
		if(map[(int)((ray->posx + ray->dirx) * ray->moveSpeed)][(int)(ray->posy)] == 0)
			ray->posx += ray->dirx * ray->moveSpeed;
		if(map[(int)(ray->posx)][(int)((ray->posy + ray->diry) * ray->moveSpeed)] == 0)
			ray->posy += ray->diry * ray->moveSpeed;
		SDL_SetRenderDrawColor(sdl->renderer,0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(sdl->renderer);
		ray->x = 0;
	}
	if (sdl->event.key.keysym.sym == SDLK_s || sdl->event.key.keysym.sym == SDLK_DOWN)
	{
		if(map[(int)((ray->posx - ray->dirx) * ray->moveSpeed)][(int)(ray->posy)] == 0)
			ray->posx -= ray->dirx * ray->moveSpeed;
		if(map[(int)(ray->posx)][(int)((ray->posy - ray->diry) * ray->moveSpeed)] == 0)
			ray->posy -= ray->diry * ray->moveSpeed;
		SDL_SetRenderDrawColor(sdl->renderer,0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(sdl->renderer);
		ray->x = 0;
	}
	if (sdl->event.type == SDL_QUIT || sdl->event.key.keysym.sym == SDLK_q || \
			sdl->event.key.keysym.sym == SDLK_ESCAPE)
                sdl->run = 0;
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
    if (ray->x == 0)
    {
    	SDL_SetRenderDrawColor(sdl->renderer, 0, 200, 255, SDL_ALPHA_OPAQUE);
    	SDL_RenderFillRect(sdl->renderer, &sdl->skybox);
    	SDL_SetRenderDrawColor(sdl->renderer, 100, 100, 100, SDL_ALPHA_OPAQUE);
    	SDL_RenderFillRect(sdl->renderer, &sdl->ground);
    }
}

int	main(void)
{
	t_raycast 	ray;
	t_sdl 	sdl;

	//make_int_array(&ray, newl);
	int n = 0;
	init_values(&ray, &sdl);
	while (sdl.run) // sdl loop (sdl event(s) will)
	{
		make_skyandground(&ray, &sdl);
		while (ray.x < ray.width)
		{
			update_map_info(&ray);
			side_dist(&ray);
			wall_detect(&ray);
			wall_height(&ray);
			colour_picker(&ray, &sdl);
			n = 1;
		}
		if (n == 1)
		{
			n = 0;
			ray.moveSpeed = 0.1;
			ray.rotSpeed = 0.05;
			SDL_RenderPresent(sdl.renderer);
			printf("Total info:\n\ncamerax = %f\nraydirx = %f		dirx = %f	planex = %f\nraydiry = %f		diry = %f	planey = %f\nmapx = %d	posx = %f	stepx = %d\nmapy = %d	posy = %f	stepy = %d\ndeltaDistx = %f \
			\ndeltaDisty = %f\nsideDistx = %f\nsideDisty = %f\nparalleWalldist = %f\nwallheight = %d\nwall_start = %d\nwall_end = %d\nside = %d\nstrafe = %d\n", \
			ray.camera_x, ray.raydirx, ray.dirx, ray.planex, ray.raydiry, ray.diry, ray.planey, ray.mapx, ray.posx, ray.stepx, ray.mapy, ray.posy, ray.stepy, ray.deltaDistx, ray.deltaDisty, ray.sideDistx, \
			ray.sideDisty, ray.parallelwalldst, ray.wallheight, ray.wall_start, ray.wall_end, ray.side, ray.strafe);
		}
		while (SDL_PollEvent(&sdl.event))
        {
			control_movement(&ray, &sdl);
			control_rotate(&ray, &sdl);
	    }
	}
	SDL_DestroyWindow(sdl.window);
	SDL_Quit();
	return (0);
}
	/*
int		wolf3d(int fd)
{
	t_array 	newl;
	int			n;

	newl.line = NULL;
	newl.joinline = NULL;
	newl.c = -1;
	newl.i = 0;
	if ((n = checknmake(&newl, fd)) != 1)
		return (n);
	raycast(&newl);
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
			if ((ret = wolf3d(fd)) == 0)
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
}*/