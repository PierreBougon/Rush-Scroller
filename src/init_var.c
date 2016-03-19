/*
** init_var.c for init in /home/bougon_p/rendu/gfx_scroller
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Mar 19 22:47:45 2016 bougon_p
** Last update Sat Mar 19 23:26:08 2016 bougon_p
*/

#include "mega.h"

int	init_var(t_data *data)
{
  data->state.menu = true;
  data->state.game = false;
  data->state.end = false;
  data->menu.start = true;
  if (init_sprites(data) == 1 || init_player(data) == 1 ||
      init_sampler(data))
    return (1);
  return (0);
}
