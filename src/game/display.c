/*
** display.c for DISPLAY in /home/bougon_p/rendu/gfx_scroller
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Mar 19 23:13:48 2016 bougon_p
** Last update Sun Mar 20 11:58:08 2016 marc brout
*/

#include "mega.h"

void	disp_game(t_data *data)
{
  draw_bg(data);
  move_player(data);
  bunny_blit(&data->window->buffer, data->back.fence,
	     &data->back.pos_fence);
  bunny_blit(&data->window->buffer, data->back.tree2,
	     &data->back.pos_tree2);
}

void	fire(t_fire *fire)
{
  rand_bottom(fire);
  calc_whole_pix(fire);
  transfer_color(fire, fire->feu);
  bunny_blit(&fire->win->buffer, &fire->pix->clipable, NULL);
}

void		mort(t_mort *mort)
{
  static char	go = 0;

  decrem(mort);
  if (!go)
    {
      mort->col += 1;
      if (mort->col >= 300)
	{
	  mort->turn += 1;
	  go = 1;
	}
    }
  else
    {
      mort->col -= 1;
      if (mort->col <= -100)
	go = 0;
    }
  bunny_blit(&mort->win->buffer, &mort->temp->clipable, NULL);
}

void	rohan(t_rohan *rohan)
{
  copy(rohan);
  rohan->turn += 1;
  bunny_blit(&rohan->win->buffer, &rohan->temp->clipable, NULL);
}

void	disp_menu(t_data *data)
{
  bunny_fill(&data->back.back->buffer, 0xFF232323);
  bunny_blit(&data->window->buffer, data->back.back, NULL);
  //display du menu enjoy les effets :)
  fire(data->menu.fire);
  rohan(data->menu.rohan);
  mort(data->menu.mort);
}

void	disp_end(UNUSED t_data *data)
{
  //display écran de fin
}
