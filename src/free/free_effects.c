/*
** free_effects.c for mega
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sun Mar 20 19:56:26 2016 marc brout
** Last update Sun Mar 20 23:34:47 2016 bougon_p
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

void		free_list(t_data *data)
{
  t_text	*elem;
  t_text	*tmp;

  elem = data->menu.txt;
  while (elem->next != NULL)
    {
      tmp = elem;
      elem = elem->next;
      bunny_free(tmp);
    }
  bunny_free(elem);
}

void		free_effects(t_data *data)
{
  bunny_delete_clipable(&data->menu.rohan->play->clipable);
  bunny_delete_clipable(&data->menu.rohan->quit->clipable);
  bunny_delete_clipable(&data->menu.mort->pix->clipable);
  free_feu(data->menu.fire);
  bunny_free(data->menu.rohan);
  bunny_free(data->menu.mort);
  bunny_free(data->menu.fire);
  bunny_delete_sound(&data->saber->sound);
  bunny_delete_sound(&data->death->sound);
}
