/*
** free_effects.c for mega
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sun Mar 20 19:56:26 2016 marc brout
** Last update Sun Mar 20 21:52:59 2016 benjamin duhieu
*/

#include "mega.h"

void		free_feu(t_fire *fire)
{
  int		i;

  i = 0;
  while (i < WIN_HEIGHT + 2)
    {
      bunny_free(fire->feu->tab[i]);
      i += 1;
    }
  bunny_free(fire->feu->tab);
  bunny_free(fire->feu);
}

void		free_effects(t_data *data)
{
  bunny_delete_clipable(&data->menu.rohan->play->clipable);
  bunny_delete_clipable(&data->menu.rohan->quit->clipable);
  bunny_delete_clipable(&data->menu.rohan->temp->clipable);
  bunny_delete_clipable(&data->menu.mort->pix->clipable);
  bunny_delete_clipable(&data->menu.fire->pix->clipable);
  free_feu(data->menu.fire);
  bunny_free(data->menu.rohan);
  bunny_free(data->menu.mort);
  bunny_free(data->menu.fire);
}
