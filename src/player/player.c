/*
** player.c for PLAYER in /home/bougon_p/rendu/gfx_scroller
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Mar 19 00:12:11 2016 bougon_p
** Last update Sat Mar 19 04:55:54 2016 bougon_p
*/

#include "mega.h"

int	init_player(t_data *data)
{
  data->player.play_pos.x = WIN_WIDTH / 2;
  data->player.play_pos.y = FLOOR - 62;
  data->player.real_pos.x = 0;
  data->player.real_pos.y = 0;
  data->player.wait = 0;
  data->player.tim = 0;
  data->player.stateright = true;
  data->player.ismoving = false;
  data->player.onborderleft = false;
  data->player.onborderright = false;
  return (0);
}

void	rotate_player_left(t_player *player)
{
  printf("ROTATE LEFT\n");
  player->sprite->scale.x = -1.0;
  player->play_pos.x += 70;
  player->stateright = false;
}

void	rotate_player_right(t_player *player)
{
  printf("ROTATE RIGHT\n");
  player->sprite->scale.x = 1.0;
  player->play_pos.x -= 70;
  player->stateright = true;
}