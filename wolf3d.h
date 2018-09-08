/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmkhize <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 09:37:16 by bmkhize           #+#    #+#             */
/*   Updated: 2018/09/03 15:49:05 by bmkhize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WOLF3D_H
# define __WOLF3D_H

# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
//# include "/goinfre/bmkhize/.brew/include/SDL2/SDL.h"
# include "SDL2/SDL.h"

# define MANUALSCALE 0
# define WIN_W 800
# define WIN_H 800

typedef struct		s_raycast
{
// this is the map stuff
	int				**map;
	int				xpos;

// the map reading values
	int				maph;
	int				mapw;

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

// which side was hit, we'll make x = 0 and y = 1
	int				side;

// the distance between all the other x and y
	double			deltaDistx;
	double			deltaDisty;

// the parallel ist the distance between the wall and player (real/euclidean dist)
	double			parallelwalldst;
	int				wallheight;

// this is where the wall will start and end.
	int 			wall_start;
	int 			wall_end;

// the hit is about whethere or not a wall was detected or not.
	int				hit;

// self expl
	int				stepx;
	int				stepy;

// these x and y values .. i dont know what i made them for maybe the camx
	int				x;
	int				y;

// c'mon its the colour
	int				colour;

// movement stuff
	double			moveSpeed;
	double			rotSpeed;

// fps and distance calc stuff...to be seen
	uint32_t		time;
	uint32_t		oldtime;

// rotation stuff
	double			olddirx;
	double			oldplanex;

	int				strafe;
}					t_raycast;

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		event;
	SDL_Rect		skybox;
	SDL_Rect		ground;
	int				run;
}					t_sdl;

/*
** Main.c
*/

void				wolf3d(t_raycast *ray, t_sdl *sdl);
int					exit_fun(int key);

/*
** raycasting.c
*/

void				update_map_info(t_raycast *ray);
void				side_dist(t_raycast *ray);
void				wall_detect(t_raycast *ray);
void				wall_height(t_raycast *ray);
void				colour_picker(t_raycast *ray, t_sdl *sdl);

/*
** controls.c
*/

void				control_rotate(t_raycast *ray, t_sdl *sdl);
void				control_movement(t_raycast *ray, t_sdl *sdl);

#endif
