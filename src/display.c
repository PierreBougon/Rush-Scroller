/*
** display.c for DISPLAY in /home/bougon_p/rendu/gfx_scroller
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Mar 19 23:13:48 2016 bougon_p
** Last update Sat Mar 19 23:20:48 2016 bougon_p
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

void	disp_menu(t_data *data)
{
  bunny_fill(&data->back.back->buffer, 0xFF232323);
  bunny_blit(&data->window->buffer, data->back.back, NULL);
  //display du menu enjoy les effets :)
}

void	disp_end(t_data *data)
{
  //display écran de fin
}
