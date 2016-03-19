/*
** delete.c for delete in /home/bougon_p/rendu/gfx_scroller
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Mar 19 15:48:30 2016 bougon_p
** Last update Sat Mar 19 16:55:52 2016 bougon_p
*/

#include "mega.h"

void	delete_all_clipables(t_data *data)
{
  bunny_delete_clipable(data->back.mount);
  bunny_delete_clipable(data->back.mount2);
  bunny_delete_clipable(data->back.sky);
  bunny_delete_clipable(data->back.sky2);
  bunny_delete_clipable(data->back.gui);
  bunny_delete_clipable(data->back.back);
  bunny_delete_clipable(data->back.grass[0]);
  bunny_delete_clipable(data->player.sprite);
}
