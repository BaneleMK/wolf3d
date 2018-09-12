/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banelord <banelord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 09:37:16 by bmkhize           #+#    #+#             */
/*   Updated: 2018/09/12 22:01:19 by banelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WOLF3D_H
# define __WOLF3D_H

# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
//# include "/goinfre/bmkhize/.brew/include/SDL2/SDL.h"
# include "SDL2/SDL.h"
/*
** the linux include file location
** # include "SDL2/SDL.h"
*/

# define MANUALSCALE 0
# define WIN_W 1300
# define WIN_H 800
# define KEYPRESSED sdl->event.key.keysym.sym
# define PRESSED sdl->event.type == SDL_KEYDOWN
# define ROT move->rotspeed
# define MSP move->movespeed

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
	double			sidedistx;
	double			sidedisty;
	int				side;
	double			deltadistx;
	double			deltadisty;
	double			parallelwalldst;
	int				wallheight;
	int				wall_start;
	int				wall_end;
	int				hit;
	int				stepx;
	int				stepy;
	int				x;
}					t_raycast;

typedef struct		s_movement
{
	double			movespeed;
	double			rotspeed;
	double			olddirx;
	double			oldplanex;
	int				mini_map;
	int				light_val;
	int				lighting;
}					t_move;

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		event;
	SDL_Rect		skybox;
	SDL_Rect		ground;
	int				run;
	int				draw;
	int				ret;
}					t_sdl;

typedef struct		s_dda
{
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			x;
	double			y;
	double			dx;
	double			dy;
	double			step;
	int				i;
	int				skystart;
	int				groundstart;
}					t_dda;

/*
** Main.c
*/

void				wolf3d(t_raycast *ray, t_sdl *sdl, t_move *move, t_dda *d);

/*
** raycasting.c
*/

void				update_map_info(t_raycast *ray);
void				side_dist(t_raycast *ray);
void				wall_detect(t_raycast *ray);
void				wall_height(t_raycast *ray);
void				colour_picker(t_raycast *ray, t_sdl *sdl, t_move *move);

/*
** controls.c
*/

void				control_rotate(t_raycast *ray, t_sdl *sdl, t_move *move);
void				control_movement(t_raycast *ray, t_sdl *sdl, t_move *move);
void				misc(t_raycast *ray, t_sdl *sdl, t_move *move);

/*
** moregraphics
*/

void				make_skyandground(t_raycast *ray, t_sdl *sdl, t_dda *d);
void				lighting(t_raycast *ray, t_move *move);
void				mini_map(t_raycast *ray);
void				drawdda(t_dda *d, t_sdl *sdl);
void				fastmake_skyandground(t_raycast *ray, t_sdl *sdl);

/*
** utility
*/

int					make_int_array(t_raycast *ray, t_array *newl);
void				init_values(t_raycast *ray, t_sdl *sdl, t_move *move);
void				drawmethod(t_raycast *ray, t_sdl *sdl);

/*
** validate
*/

int					mapvalues(t_raycast *ray, int x, int y);
int					mapisvalid(t_raycast *ray);


#endif
