/*
** check_menu.c for MENU in /home/bougon_p/rendu/gfx_scroller
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Mar 20 22:00:03 2016 bougon_p
** Last update Sun Mar 20 22:12:23 2016 bougon_p
*/

#include "mega.h"

void	choose_button(t_data *data, t_bunny_keysym keysym)
{
  if (keysym == BKS_DOWN)
    {
      if (data->menu.start)
	data->menu.start = false;
      else
	data->menu.start = true;
    }
  else if (keysym == BKS_UP)
    {
      if (data->menu.start)
	data->menu.start = false;
      else
	data->menu.start = true;
    }
}

int	check_menu(t_data *data, t_bunny_keysym keysym)
{
  if (keysym == BKS_ESCAPE)
    {
      data->state.menu = true;
      data->state.game = false;
      data->state.fondu = false;
    }
  if (data->state.menu)
    {
      choose_button(data, keysym);
      if (data->menu.start && keysym == BKS_RETURN)
	{
	  data->state.menu = false;
	  data->state.game = true;
	}
      else if (!data->menu.start && keysym == BKS_RETURN)
	return (1);
    }
  return (0);
}
