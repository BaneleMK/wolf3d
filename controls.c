#include "wolf3d.h"

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
    	ray->x = 0;
	}
}

void    control_movement(t_raycast *ray, t_sdl *sdl)
{
    if (sdl->event.key.keysym.sym == SDLK_w || sdl->event.key.keysym.sym == SDLK_UP)
	{
		if(ray->map[(int)(ray->posy)][(int)(ray->posx + ray->dirx * ray->moveSpeed)] == 0)
		    ray->posx += ray->dirx * ray->moveSpeed; 
		if(ray->map[(int)(ray->posy + ray->diry * ray->moveSpeed)][(int)(ray->posx)] == 0)
	        ray->posy += ray->diry * ray->moveSpeed;
		ray->x = 0;
	}
	if (sdl->event.key.keysym.sym == SDLK_s || sdl->event.key.keysym.sym == SDLK_DOWN)
	{
		if(ray->map[(int)(ray->posy)][(int)(ray->posx - ray->dirx * ray->moveSpeed)] == 0)
    	    ray->posx -= ray->dirx * ray->moveSpeed; 
		if(ray->map[(int)(ray->posy - ray->diry * ray->moveSpeed)][(int)(ray->posx)] == 0)
	        ray->posy -= ray->diry * ray->moveSpeed;        
		ray->x = 0;
	}
	if (sdl->event.type == SDL_QUIT || sdl->event.key.keysym.sym == SDLK_q || \
			sdl->event.key.keysym.sym == SDLK_ESCAPE)
                sdl->run = 0;
}