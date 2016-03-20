/*
** delete.c for delete in /home/bougon_p/rendu/gfx_scroller
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Mar 19 15:48:30 2016 bougon_p
** Last update Sun Mar 20 23:21:36 2016 bougon_p
*/

#include "mega.h"

void	delete_all_clipables(t_data *data)
{
  bunny_delete_clipable(data->back.mount);
  bunny_delete_clipable(data->back.tree);
  bunny_delete_clipable(data->back.tree2);
  bunny_delete_clipable(data->back.sky);
  bunny_delete_clipable(data->back.gui);
  bunny_delete_clipable(data->back.back);
  bunny_delete_clipable(data->back.rabbit);
  bunny_delete_clipable(data->back.grass);
  bunny_delete_clipable(data->back.grass2);
  bunny_delete_clipable(data->player.attck);
  bunny_delete_clipable(data->player.sprite);
  bunny_delete_clipable(data->player.stay);
  bunny_delete_clipable(&data->end.plsm.pixarray->clipable);
  bunny_delete_clipable(&data->pixarray->clipable);
}
