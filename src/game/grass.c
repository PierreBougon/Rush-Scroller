/*
** grass.c for grass in /home/duhieu_b/infographie/gfx_scroller/src
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sat Mar 19 16:23:53 2016 benjamin duhieu
** Last update Sun Mar 20 22:06:03 2016 marc brout
*/

#include "mega.h"

void	draw_grass(t_data *data)
{
  int	count;
  int	y;
  int	i;

  i = -1;
  y = FLOOR;
  while (++i < 3)
    {
      count = -1;
      while (++count < 2)
	{
	  data->back.pos_grass[i].y = y;
	  data->back.pos_grass2[i].y = y;
	  y += 28;
	  bunny_blit(&data->window->buffer, data->back.grass,
		     &data->back.pos_grass[i]);
	  bunny_blit(&data->window->buffer, data->back.grass2,
		     &data->back.pos_grass2[i]);
	}
    }
}

void	grass_move(t_data *d, int j)
{
  int	i;

  i = -1;
  while (++i < 3)
    {
      d->back.pos_grass[i].x += j * (1 + i);
      d->back.pos_grass2[i].x += j * (1 + i);
      if (j == -1)
	{
	  if (d->back.pos_grass[i].x <= -d->back.grass->clip_width)
	    d->back.pos_grass[i].x = d->back.grass->clip_width;
	  if (d->back.pos_grass2[i].x <= -d->back.grass2->clip_width)
	    d->back.pos_grass2[i].x = d->back.grass2->clip_width;
	}
      if (j == 1)
	{
	  if (d->back.pos_grass[i].x >= d->back.grass->clip_width)
	    d->back.pos_grass[i].x = -d->back.grass->clip_width;
	  if (d->back.pos_grass2[i].x >= d->back.grass2->clip_width)
	    d->back.pos_grass2[i].x = -d->back.grass2->clip_width;
	}
    }
}
