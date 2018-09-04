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

//void	raycast(t_array *newl)
int	main(void)
{
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
	t_raycast 	ray;

	//make_int_array(&ray, newl);
	t_sdl 	sdl;
	ray.width = 100;
	ray.height = 100;
	ray.posx = 22;
	ray.posy = 12;
	ray.dirx = -1;
	ray.diry = 0;
	ray.x = 1;
	int n = 1;
	ray.planex = 0;
	ray.planey = 0.66;
	sdl.run = 1;
	sdl.renderer = NULL;
	sdl.window = NULL;
//	printf("im hitting out\n");
//	(void)newl;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_CreateWindowAndRenderer(WIN_W, WIN_H, 0, &sdl.window, &sdl.renderer);
	//sdl.window = SDL_CreateWindow("go for bronze", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_W, WIN_H, SDL_WINDOW_RESIZABLE);
	while (sdl.run) // sdl loop (sdl event(s) will)
	{
		//printf("im hitting in\n");
		while (ray.x < WIN_W)
		{
			n = 1;
			//printf("im hitting in wayyy in\n");
			ray.camera_x = 2 * ray.x / WIN_W - 1;
			ray.raydirx = (ray.dirx + ray.planex) * ray.camera_x;
			ray.raydiry = (ray.diry + ray.planey) * ray.camera_x;

			ray.mapx = (int)ray.posx;
			ray.mapy = (int)ray.posy;

			ray.deltaDistx = fabs(1 / ray.raydirx);
			ray.deltaDisty = fabs(1 / ray.raydiry);

			// ill split it here;
			if (ray.raydirx > 0)
			{
				//delta dist x is for the euclidean distance aka real distance.
				ray.sideDistx = (ray.mapx - ray.posx + 1) * ray.deltaDistx;
				ray.stepx = 1;
			}
			else
			{
				ray.sideDistx = (ray.mapx - ray.posx) * ray.deltaDistx;
				ray.stepx = -1;
			}
			if (ray.raydiry > 0)
			{
				ray.sideDistx = (ray.mapy - ray.posy + 1) * ray.deltaDisty;
				ray.stepy = 1;
			}
			else
			{
				ray.sideDistx = (ray.mapy - ray.posy) * ray.deltaDisty;
				ray.stepy = -1;
			}
			ray.hit = 0;
			while (ray.hit == 0)
			{
				//printf("hit dat wall in\n");
				if (ray.sideDistx > ray.sideDisty)
				{
					ray.sideDisty += ray.deltaDisty;
					ray.mapx += 1;
					ray.side = 0;
				}
				else
				{
					ray.sideDistx += ray.deltaDistx;
					ray.mapy += 1;
					ray.side = 1;
				}
				if (map[ray.mapy][ray.mapx] > 0){
					ray.hit = 1;
				}
			}
			//printf("hit dat in\n");
			if (ray.side == 0)
				ray.parallelwalldst = (ray.mapx - ray.posx + \
				 ((1 - ray.stepx) / 2)) / ray.raydirx ;
			else
				ray.parallelwalldst = (ray.mapy - ray.posy + \
				 ((1 - ray.stepy) / 2)) / ray.raydiry ;
			// this should be and int in order not to have walls of different heights 
			ray.wallhight = (WIN_H / ray.parallelwalldst);
			//printf("almost to the draw\n");

			// the reason that this was all done this way is so 
			// that the the wall is centered to the middle of the screen the specifics still confuse me.
			ray.wall_start = -ray.wallhight / 2 + WIN_H / 2;
			if (ray.wall_start < 0)
				ray.wall_start = 0;
			ray.wall_end = ray.wallhight / 2 + WIN_H / 2;
			if (ray.wall_end >= ray.height)
				ray.wall_end = ray.height - 1;

			//printf("almost there colours now\n");

			if (ray.side == 0)
				SDL_SetRenderDrawColor(sdl.renderer, 0, 255, 255 / 2,SDL_ALPHA_OPAQUE);
			else
				SDL_SetRenderDrawColor(sdl.renderer,0, 0, 255, SDL_ALPHA_OPAQUE);
			//lets render
			//printf("now....draw\n");

            SDL_RenderDrawLine(sdl.renderer, ray.x, ray.wall_start, ray.x, ray.wall_end);
			//printf("drew\n");
			ray.x++;	
		}
		if (n == 1)
		{
			n = 0;
			ray.moveSpeed = 5.0;
			ray.rotSpeed = 2.5;
			SDL_RenderPresent(sdl.renderer);
		}
		while (SDL_PollEvent(&sdl.event))
        {
			//printf("whew\n");
			if (sdl.event.key.keysym.sym == SDLK_w || sdl.event.key.keysym.sym == SDLK_DOWN)
			{
				if(map[(int)(ray.posx + ray.dirx * ray.moveSpeed)][(int)(ray.posy)])
				{
					ray.posx += ray.dirx * ray.moveSpeed;
					//printf("Sy - pos | x = %f | y = %f\n", ray.posx, ray.posy);
				}
				if(map[(int)(ray.posx)][(int)(ray.posy + ray.diry * ray.moveSpeed)])
				{
					ray.posy += ray.diry * ray.moveSpeed;
					//printf("Sy - pos | x = %f | y = %f\n", ray.posx, ray.posy);
				}
				//printf("w - x = %d | y = %d\n", (int)(ray.posx + ray.dirx * ray.moveSpeed), (int)(ray.posy + ray.diry * ray.moveSpeed));
				SDL_SetRenderDrawColor(sdl.renderer,0, 0, 0, SDL_ALPHA_OPAQUE);
				SDL_RenderClear(sdl.renderer);
				ray.x = 1;
			}
			if (sdl.event.key.keysym.sym == SDLK_s || sdl.event.key.keysym.sym == SDLK_UP)
			{
				if(map[(int)(ray.posx - ray.dirx * ray.moveSpeed)][(int)(ray.posy)])
				{
					ray.posx -= ray.dirx * ray.moveSpeed;
					//printf("Sx - pos | x = %f | y = %f\n", ray.posx, ray.posy);
				}
				if(map[(int)(ray.posx)][(int)(ray.posy - ray.diry * ray.moveSpeed)])
				{
					ray.posy -= ray.diry * ray.moveSpeed;
					//printf("Sy - pos | x = %f | y = %f\n", ray.posx, ray.posy);
				}
				//printf("s - x = %d | y = %d\n", (int)(ray.posx - ray.dirx * ray.moveSpeed), (int)(ray.posy - ray.diry * ray.moveSpeed));
				SDL_SetRenderDrawColor(sdl.renderer,0, 0, 0, SDL_ALPHA_OPAQUE);
				SDL_RenderClear(sdl.renderer);
				ray.x = 1;
			}
			if (sdl.event.key.keysym.sym == SDLK_a || sdl.event.key.keysym.sym == SDLK_LEFT)
			{
				ray.olddirx = ray.dirx;
				ray.dirx = ray.dirx * cos(-ray.rotSpeed) - ray.diry * sin(-ray.rotSpeed);
				ray.diry = ray.olddirx * sin(-ray.rotSpeed) + ray.diry * cos(-ray.rotSpeed);
				ray.oldplanex = ray.planex;
				ray.planex = ray.planex * cos(-ray.rotSpeed) - ray.planex * sin(-ray.rotSpeed);
				ray.planey = ray.olddirx * sin(-ray.rotSpeed) - ray.planey * cos(-ray.rotSpeed);
				SDL_SetRenderDrawColor(sdl.renderer,0, 0, 0, SDL_ALPHA_OPAQUE);
				SDL_RenderClear(sdl.renderer);
				ray.x = 0;
			}
			if (sdl.event.key.keysym.sym == SDLK_d || sdl.event.key.keysym.sym == SDLK_RIGHT)
			{
				ray.olddirx = ray.dirx;
				ray.dirx = ray.dirx * cos(ray.rotSpeed) - ray.diry * sin(ray.rotSpeed);
				ray.diry = ray.olddirx * sin(ray.rotSpeed) + ray.diry * cos(ray.rotSpeed);
				ray.oldplanex = ray.planex;
				ray.planex = ray.planex * cos(ray.rotSpeed) - ray.planex * sin(ray.rotSpeed);
				ray.planey = ray.olddirx * sin(ray.rotSpeed) - ray.planey * cos(ray.rotSpeed);
				SDL_SetRenderDrawColor(sdl.renderer,0, 0, 0, SDL_ALPHA_OPAQUE);
				SDL_RenderClear(sdl.renderer);
				ray.x = 0;
			}
			if (sdl.event.type == SDLK_c)
            {
				printf("JUST DO IT!!!!\n\n\n");
				SDL_SetRenderDrawColor(sdl.renderer,0, 0, 0, SDL_ALPHA_OPAQUE);
				SDL_RenderClear(sdl.renderer);
				SDL_Delay(10000);
            }
	        if (sdl.event.type == SDL_QUIT || sdl.event.key.keysym.sym == SDLK_q)
            {
				printf("S - pos | x = %f | y = %f\n", ray.posx, ray.posy);
                sdl.run = 0;
            }
			printf("x = %d | y = %d\n", (int)(ray.posx), (int)(ray.posy));
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