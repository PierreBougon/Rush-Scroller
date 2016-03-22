/*
** player_moves.c for MOVEMENT in /home/bougon_p/rendu/gfx_scroller
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Mar 19 02:01:36 2016 bougon_p
** Last update Mon Mar 21 12:27:52 2016 bougon_p
*/

#include "mega.h"

void	refresh_player_realpos(t_player *player)
{
  if (player->ismoving && player->stateright &&
      player->real_pos.x < END_GAME)
    player->real_pos.x += 1;
  if (player->ismoving && !player->stateright && player->real_pos.x > 0)
    player->real_pos.x -= 1;
}

void	refresh_player_pos(t_player *player)
{
  if (player->ismoving == true)
    {
      refresh_player_realpos(player);
      if (player->stateright == false
	  && player->play_pos.x > LIMIT_LEFT
	  && player->real_pos.x > 0)
        {
	  player->play_pos.x -= 4;
	  player->onborderleft = false;
	  player->onborderright = false;
	}
      if (player->stateright == true
      	  && player->play_pos.x < LIMIT_RIGHT
	  && player->real_pos.x < END_GAME)
      	{
      	  player->play_pos.x += 4;
      	  player->onborderleft = false;
      	  player->onborderright = false;
      	}
      if (player->play_pos.x <= LIMIT_LEFT)
      	player->onborderleft = true;
      else if (player->play_pos.x >= LIMIT_RIGHT)
	player->onborderright = true;
    }
}

void	check_player_movement(t_data *data, t_bunny_keysym keysym,
                              t_bunny_event_state state)
{
  if (keysym == BKS_RIGHT
      && data->player.stateright == false)
    {
      rotate_player_right(&data->player);
      data->player.ismoving = true;
    }
  else if (keysym == BKS_RIGHT)
    data->player.ismoving = true;
  if (keysym == BKS_LEFT && state == GO_DOWN
      && data->player.stateright == true)
    {
      rotate_player_left(&data->player);
      data->player.ismoving = true;
    }
  else if (keysym == BKS_LEFT)
    data->player.ismoving = true;
  if (keysym == BKS_SPACE)
    {
      if (!data->player.isattack)
	bunny_sound_play(&data->saber->sound);
      data->player.isattack = true;
      data->player.ismoving = false;
    }
}
