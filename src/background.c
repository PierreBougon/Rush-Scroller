/*
** background.c for BG in /home/bougon_p/rendu/gfx_scroller
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Mar 19 03:27:05 2016 bougon_p
** Last update Sat Mar 19 16:27:07 2016 benjamin duhieu
*/

#include "mega.h"

void	draw_right(t_data *data)
{
  static int	i = 0;

  if (!(i % 12))
    {
      data->back.pos_mount.x -= 1;
      data->back.pos_mount2.x -= 1;
    }
  data->back.pos_rab.x -= 1;
  data->back.pos_fence.x -= 2;
  data->back.pos_tree.x -= 1;
  data->back.pos_tree2.x -= 3;
  grass_move(data, -1);
  check_on_my_right(data);
  i++;
}

void	draw_left(t_data *data)
{
  static int	i = 0;

  if (!(i % 12))
    {
      data->back.pos_mount.x += 1;
      data->back.pos_mount2.x += 1;
    }
  data->back.pos_rab.x += 1;
  data->back.pos_fence.x += 2;
  data->back.pos_tree.x += 1;
  data->back.pos_tree2.x += 3;
  grass_move(data, 1);
  check_on_my_left(data);
  i--;
}

void	draw_sky(t_data *data)
{
  static int	i = 0;

  if (!(i % 5))
    {
      data->back.pos_sky.x -= 1;
      data->back.pos_sky2.x -= 1;
    }
  if (data->back.pos_sky.x <= -data->back.sky->clip_width)
    data->back.pos_sky.x = data->back.back->clip_width;
  if (data->back.pos_sky2.x <= -data->back.sky2->clip_width)
    data->back.pos_sky2.x = data->back.back->clip_width;
  i++;
}

void	draw_bg(t_data *data)
{
  bunny_fill(&data->back.back->buffer, SKY);
  draw_sky(data);
  if (data->player.stateright && data->player.onborderright
      && data->player.ismoving)
    draw_right(data);
  else if (!data->player.stateright && data->player.onborderleft
	   && data->player.ismoving)
    draw_left(data);
  bunny_blit(&data->window->buffer, data->back.back, NULL);
  bunny_blit(&data->window->buffer, data->back.sky,
  	     &data->back.pos_sky);
  bunny_blit(&data->window->buffer, data->back.sky2,
  	     &data->back.pos_sky2);
  bunny_blit(&data->window->buffer, data->back.mount,
  	     &data->back.pos_mount);
  bunny_blit(&data->window->buffer, data->back.mount2,
  	     &data->back.pos_mount2);
  bunny_blit(&data->window->buffer, data->back.rabbit, &data->back.pos_rab);
  bunny_blit(&data->window->buffer, data->back.tree, &data->back.pos_tree);
  draw_grass(data);
}
