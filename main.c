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

void	make_int_array(t_raycast *ray, t_array *newl)
{
	char	**str;

	ray->height = 0;
	ray->map = (int **)malloc(sizeof(int *) * newl->no_lines);
	printf("no_lines = %ld\n", newl->no_lines);
	while (ray->height < newl->no_lines)
	{
		ray->width = 0;
		str = ft_strsplit(newl->arrays[ray->height], ' ');
		printf("\nstr %ld : %s\n", ray->height, str[ray->width]);
		ray->map[newl->height] = (int *)malloc(sizeof(int) * newl->c);
		while(ray->width < newl->c)
		{
			//printf("we in w = %ld & h = %ld str = %d\n", ray->width, ray->height, ft_atoi(str[ray->width]));
			ray->map[ray->height][ray->width] = ft_atoi(str[ray->width]);
			printf("%d ", ray->map[ray->height][ray->width]);
			ray->width++;
		}
		ft_putchar('\n');
		ft_freearray(str, newl->c);
		ray->height++;
	}
}

void	raycast(t_array *newl)
{
	t_raycast 	ray;

	make_int_array(&ray, newl);
	/*ray.posx = 2;
	ray.posy = 2;
	ray.dirx = -1;
	ray.diry = 0;
	ray.planex = 0;
	ray.planey = 0.66;
	while (1) // sdl loop (sdl event(s) will)
	{
		while (ray.x_itter < ray.width)
		{
			ray.camera_x = 2 * ray.x / ray.width - 1;
			ray.raydirx = (ray.dirx + ray.planex) * ray.camera_x;
			ray.raydiry = (ray.diry + ray.planey) * ray.camera_x;

			ray.mapx = (int)ray.posx;
			ray.mapy = (int)ray.posy;

			ray.deltaDistx = fabs(1 / ray.raydirx);
			ray.deltaDisty = fabs(1 / ray.raydiry);
		}
	}*/
}

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
}
