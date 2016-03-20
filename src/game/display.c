/*
** display.c for DISPLAY in /home/bougon_p/rendu/gfx_scroller
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Mar 19 23:13:48 2016 bougon_p
** Last update Sun Mar 20 19:10:05 2016 benjamin duhieu
*/

#include <string.h>
#include "mega.h"

void	disp_game(t_data *data)
{
  if (data->player.real_pos.x >= 0 && data->player.real_pos.x <= END_GAME)
    draw_bg(data);
  move_player(data);
  if (data->player.real_pos.x >= 0 && data->player.real_pos.x <= END_GAME)
    {
      bunny_blit(&data->window->buffer, data->back.fence,
		 &data->back.pos_fence);
      bunny_blit(&data->window->buffer, data->back.tree2,
		 &data->back.pos_tree2);
    }
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
  data->menu.pos.x--;
  if (data->menu.pos.x <= -data->letters)
    data->menu.pos.x = data->menu.scr->clipable.clip_width;
  fire(data->menu.fire);
  rohan(data->menu.rohan);
  mort(data->menu.mort);
  disp_text(data->menu.txt, &data->menu, data->str);
  bunny_blit(&data->window->buffer, &data->menu.scr->clipable, NULL);
}

void	disp_end(t_data *data)
{
  plasma(data);
}
