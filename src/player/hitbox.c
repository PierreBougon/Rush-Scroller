/*
** hitbox.c for HITBOX in /home/bougon_p/rendu/gfx_scroller
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Mar 20 12:12:20 2016 bougon_p
** Last update Sun Mar 20 19:34:55 2016 bougon_p
*/

#include "mega.h"

void	check_end_game(t_data *data)
{
  if (data->player.real_pos.x == END_GAME)
    {
      data->state.game = false;
      data->state.end = true;
      /* if (!(data->end.starfield = */
      /* 	    bunny_new_pixelarray(WIN_WIDTH, WIN_HEIGHT)) || */
      /* 	  !(data->end.bck = */
      /* 	    bunny_new_pixelarray(WIN_WIDTH, WIN_HEIGHT))) */
      /* 	exit(1); */
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
