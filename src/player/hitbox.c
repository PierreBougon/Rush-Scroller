/*
** hitbox.c for HITBOX in /home/bougon_p/rendu/gfx_scroller
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Mar 20 12:12:20 2016 bougon_p
** Last update Sun Mar 20 22:09:08 2016 marc brout
*/

#include "mega.h"

void	check_end_game(t_data *data)
{
  if (data->player.real_pos.x == END_GAME)
    {
      data->state.game = false;
      data->state.end = true;
    }
}

void	check_murder(t_data *data)
{
  if ((data->player.stateright
       && data->back.pos_rab.x <= data->player.play_pos.x + HITBOX
       && data->back.pos_rab.x > data->player.play_pos.x
       && data->player.isattack)
      || (!data->player.stateright
          && data->back.pos_rab.x >= data->player.play_pos.x - HITBOX
          && data->back.pos_rab.x < data->player.play_pos.x
	  && data->player.isattack))
    {
      data->kill = 1;
      data->back.pos_rab.x =
        rand() % data->back.mount->clip_width + data->back.back->clip_width;
      bunny_sound_play(&data->death->sound);
    }
}
