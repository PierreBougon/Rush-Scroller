/*
** plasma.c for plasma in /home/bougon_p/rendu/gfx_incendie
**
** Made by Pierre Bougon
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Dec  6 13:59:15 2015 Pierre Bougon
** Last update Sun Mar 20 18:22:30 2016 bougon_p
*/

#include "mega.h"

int	set_plasma(t_plsm *plsm)
{
  draw_plasma(plsm);
  return (0);
}

int		plasma(t_data *data)
{
  t_plsm        *plsm;

  plsm = &data->end.plsm;
  plsm->modif += 0.05;
  plsm->zoom += 0.05;
  plsm->move += 4;
  set_plasma(plsm);
  bunny_blit(&data->window->buffer, &plsm->pixarray->clipable, 0);
  return (0);
}
