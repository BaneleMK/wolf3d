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
# include "/goinfre/bmkhize/.brew/include/SDL2/SDL.h"

//# include "SDL2/SDL.h"

# define MANUALSCALE 0
# define WIN_W 800
# define WIN_H 800

typedef struct		s_raycast
{
	int				**map;
	int				maph;
	int				mapw;
	long			width;
	long			height;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			camera_x;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	double			sideDistx;
	double			sideDisty;
	int				side;
	double			deltaDistx;
	double			deltaDisty;
	double			parallelwalldst;
	int				wallheight;
	int 			wall_start;
	int 			wall_end;
	int				hit;
	int				stepx;
	int				stepy;
	int				x;
}					t_raycast;

typedef struct 	s_movement
{
	double			moveSpeed;
	double			rotSpeed;
	double			olddirx;
	double			oldplanex;
}				t_move;

// fps and distance calc stuff...to be seen
	//uint32_t		time;
	//uint32_t		oldtime;

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

void				wolf3d(t_raycast *ray, t_sdl *sdl, t_move *move);
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

void				control_rotate(t_raycast *ray, t_sdl *sdl, t_move *move);
void				control_movement(t_raycast *ray, t_sdl *sdl, t_move *move);

#endif
