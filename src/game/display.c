/*
** display.c for DISPLAY in /home/bougon_p/rendu/gfx_scroller
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Mar 19 23:13:48 2016 bougon_p
** Last update Sun Mar 20 13:49:05 2016 bougon_p
*/

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

void	disp_menu(UNUSED t_data *data)
{
  bunny_fill(&data->back.back->buffer, 0xFF232323);
  bunny_blit(&data->window->buffer, data->back.back, NULL);
  //display du menu enjoy les effets :)
}

void	disp_end(UNUSED t_data *data)
{
  bunny_fill(&data->back.back->buffer, 0xFF232323);
  bunny_blit(&data->window->buffer, data->back.back, NULL);
  //display écran de fin
}
