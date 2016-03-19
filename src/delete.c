/*
** delete.c for delete in /home/bougon_p/rendu/gfx_scroller
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Mar 19 15:48:30 2016 bougon_p
** Last update Sat Mar 19 19:57:51 2016 benjamin duhieu
*/

#include "mega.h"

/* void	delete_grass(t_data *data) */
/* { */
/*   int	i; */

/*   i = -1; */
/*   while (++i < 3) */
/*     { */
/*       bunny_delete_clipable(data->back.grass[i]); */
/*       bunny_delete_clipable(data->back.grass2[i]); */
/*     } */
/* } */

void	delete_all_clipables(t_data *data)
{
  bunny_delete_clipable(data->back.mount);
  /* bunny_delete_clipable(data->back.mount2); */
  bunny_delete_clipable(data->back.tree);
  bunny_delete_clipable(data->back.tree2);
  bunny_delete_clipable(data->back.sky);
  /* bunny_delete_clipable(data->back.sky2); */
  bunny_delete_clipable(data->back.gui);
  bunny_delete_clipable(data->back.back);
  bunny_delete_clipable(data->back.rabbit);
  bunny_delete_clipable(data->player.sprite);
  bunny_delete_clipable(data->back.grass);
  /* delete_grass(data); */
}
