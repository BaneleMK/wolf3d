#include "wolf3d.h"

void    control_rotate(t_raycast *ray, t_sdl *sdl, t_move *move)
{

    if (sdl->event.key.keysym.sym == SDLK_a || sdl->event.key.keysym.sym == SDLK_LEFT)
    {
    	move->olddirx = ray->dirx;
    	ray->dirx = ray->dirx * cos(move->rotSpeed) - ray->diry * sin(move->rotSpeed);
    	ray->diry = move->olddirx * sin(move->rotSpeed) + ray->diry * cos(move->rotSpeed);
    	move->oldplanex = ray->planex;
    	ray->planex = ray->planex * cos(move->rotSpeed) - ray->planey * sin(move->rotSpeed);
    	ray->planey = move->oldplanex * sin(move->rotSpeed) + ray->planey * cos(move->rotSpeed);
    	ray->x = 0;
    }
    if (sdl->event.key.keysym.sym == SDLK_d || sdl->event.key.keysym.sym == SDLK_RIGHT)
    {
    	move->olddirx = ray->dirx;
    	ray->dirx = ray->dirx * cos(-move->rotSpeed) - ray->diry * sin(-move->rotSpeed);
    	ray->diry = move->olddirx * sin(-move->rotSpeed) + ray->diry * cos(-move->rotSpeed);
    	move->oldplanex = ray->planex;
    	ray->planex = ray->planex * cos(-move->rotSpeed) - ray->planey * sin(-move->rotSpeed);
    	ray->planey = move->oldplanex * sin(-move->rotSpeed) + ray->planey * cos(-move->rotSpeed);
    	ray->x = 0;
	}
}

void    control_movement(t_raycast *ray, t_sdl *sdl, t_move *move)
{
    if (sdl->event.key.keysym.sym == SDLK_w || sdl->event.key.keysym.sym == SDLK_UP)
	{
		if(ray->map[(int)(ray->posy)][(int)(ray->posx + ray->dirx * move->moveSpeed)] == 0)
		    ray->posx += ray->dirx * move->moveSpeed; 
		if(ray->map[(int)(ray->posy + ray->diry * move->moveSpeed)][(int)(ray->posx)] == 0)
	        ray->posy += ray->diry * move->moveSpeed;
		ray->x = 0;
	}
	if (sdl->event.key.keysym.sym == SDLK_s || sdl->event.key.keysym.sym == SDLK_DOWN)
	{
		if(ray->map[(int)(ray->posy)][(int)(ray->posx - ray->dirx * move->moveSpeed)] == 0)
    	    ray->posx -= ray->dirx * move->moveSpeed; 
		if(ray->map[(int)(ray->posy - ray->diry * move->moveSpeed)][(int)(ray->posx)] == 0)
	        ray->posy -= ray->diry * move->moveSpeed;        
		ray->x = 0;
	}
	if (sdl->event.type == SDL_QUIT || sdl->event.key.keysym.sym == SDLK_q || \
			sdl->event.key.keysym.sym == SDLK_ESCAPE)
                sdl->run = 0;
}