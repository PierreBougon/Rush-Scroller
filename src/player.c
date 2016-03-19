/*
** player.c for PLAYER in /home/bougon_p/rendu/gfx_scroller
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Mar 19 00:12:11 2016 bougon_p
** Last update Sat Mar 19 02:03:15 2016 bougon_p
*/

#include "mega.h"

int	init_player(t_data *data)
{
  data->player.play_pos.x = WIN_WIDTH / 2;
  data->player.play_pos.y = WIN_HEIGHT / 2;
  data->player.wait = 0;
  data->player.tim = 0;
  data->player.stateright = true;
  data->player.ismoving = false;
  return (0);
}

void	rotate_player_left(t_player *player)
{
  printf("ROTATE LEFT\n");
  player->sprites[0]->scale.x = -1.0;
  player->sprites[1]->scale.x = -1.0;
  player->sprites[2]->scale.x = -1.0;
  player->sprites[3]->scale.x = -1.0;
  player->sprites[4]->scale.x = -1.0;
  player->sprites[5]->scale.x = -1.0;
  player->sprites[6]->scale.x = -1.0;
  player->sprites[7]->scale.x = -1.0;
  player->sprites[8]->scale.x = -1.0;
  player->sprites[9]->scale.x = -1.0;
  player->play_pos.x += 64;
  player->stateright = false;
}

void	rotate_player_right(t_player *player)
{
  printf("ROTATE RIGHT\n");
  player->sprites[0]->scale.x = 1.0;
  player->sprites[1]->scale.x = 1.0;
  player->sprites[2]->scale.x = 1.0;
  player->sprites[3]->scale.x = 1.0;
  player->sprites[4]->scale.x = 1.0;
  player->sprites[5]->scale.x = 1.0;
  player->sprites[6]->scale.x = 1.0;
  player->sprites[7]->scale.x = 1.0;
  player->sprites[8]->scale.x = 1.0;
  player->sprites[9]->scale.x = 1.0;
  player->play_pos.x -= 64;
  player->stateright = true;
}
