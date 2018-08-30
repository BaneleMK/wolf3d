/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmkhize <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 09:37:16 by bmkhize           #+#    #+#             */
/*   Updated: 2018/08/30 09:37:20 by bmkhize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WOLF3D_H
# define __WOLF3D_H

# include "libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>

# define MANUALSCALE 0

typedef struct		s_raycast
{
// this is the map stuff
	int				**map;
	int				x_itter;

// the len of the box.
	long			width;
	long			height;

// player actual location.
	double			posx;
	double			posy;

// direction the player is looking.
	double			dirx;
	double			diry;

// the cam
	double			planex;
	double			planey;

 // what is this?
	double			camera_x;

// where are the rays facing
	double			raydirx;
	double			raydiry;

// the box / square the player is at.
	int				mapx;
	int				mapy;

// the distance between the nearest x and y / intial
	double			sideDistx;
	double			sideDisty;

// the distance between all the other x and y
	double			deltaDistx;
	double			deltaDisty;

// the parallel is the heigth of the wall ??? / the hit is about 
	double			parallelwalldst;
	int				hit;

	int				stepx;
	int				stepy;

	int				x;
	int				y;

	int				time;
	int				oldtime;
}					t_raycast;


/*
** Main.c
*/

int					wolf3d(int fd);
int					exit_fun(int key);

/*
** draw.c
*/

/*
** utility.c
*/
#endif
