/*
** init_var.c for init in /home/bougon_p/rendu/gfx_scroller
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Mar 19 22:47:45 2016 bougon_p
** Last update Sun Mar 20 11:57:26 2016 marc brout
*/

#include "mega.h"

int	init_rohan(t_data *data)
{
  if (!(data->menu.rohan = bunny_malloc(sizeof(t_rohan))) ||
      !(data->menu.rohan->pix =
	bunny_load_pixelarray("./img/rohan.jpg")))
    return (1);
  data->menu.rohan->temp = data->pixarray;
  data->menu.rohan->win = data->window;
  data->menu.rohan->decal = 0;
  data->menu.rohan->turn = 0;
  return (0);
}

int	init_mort(t_data *data)
{
  if (!(data->menu.mort = bunny_malloc(sizeof(t_mort))) ||
	!(data->menu.mort->pix =
	  bunny_load_pixelarray("./img/megaman.png")))
    return (1);
  data->menu.mort->temp = data->pixarray;
  data->menu.mort->win = data->window;
  data->menu.mort->col = 255;
  data->menu.mort->turn = 1;
  return (0);
}

int	init_fire(t_data *data)
{
  if (!(data->menu.fire = bunny_malloc(sizeof(t_fire))) ||
      !(data->menu.fire->feu = bunny_malloc(sizeof(t_feu))))
    return (1);
  data->menu.fire->decal = 0;
  data->menu.fire->pix = data->pixarray;
  data->menu.fire->win = data->window;
  set_palette(data->menu.fire);
  if (init_struct(data->menu.fire->feu))
    return (1);
  return (0);
}

int	init_var(t_data *data)
{
  data->state.menu = true;
  data->state.game = false;
  data->state.end = false;
  data->menu.start = true;
  if (init_sprites(data) == 1 || init_player(data) == 1 ||
      init_sampler(data) || init_fire(data) || init_mort(data) ||
      init_rohan(data))
    return (1);
  return (0);
}
