/*
** init_var.c for init in /home/bougon_p/rendu/gfx_scroller
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Mar 19 22:47:45 2016 bougon_p
** Last update Sun Mar 20 12:05:45 2016 benjamin duhieu
*/

#include "mega.h"

int	init_var(t_data *data)
{
  data->menu.scr = data->pixarray;
  data->menu.pos.x = data->menu.scr->clipable.clip_width;
  data->menu.pos.y = 100;
  if (!(data->menu.txt =
	char_to_list("abcdefghijklmnopqrstuvwxyz1234567890,.:'-<>!")))
    return (1);
  data->state.menu = true;
  data->state.game = false;
  data->state.end = false;
  data->menu.start = true;
  if (init_sprites(data) == 1 || init_player(data) == 1 ||
      init_sampler(data))
    return (1);
  return (0);
}
