/*
** player_moves.c for MOVEMENT in /home/bougon_p/rendu/gfx_scroller
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Mar 19 02:01:36 2016 bougon_p
** Last update Sat Mar 19 18:48:17 2016 bougon_p
*/

#include "mega.h"

void	check_murder(t_data *data)
{
  if ((data->player.stateright
       && data->back.pos_rab.x <= data->player.play_pos.x + HITBOX
       && data->back.pos_rab.x >data->player.play_pos.x)
      || (!data->player.stateright
	  && data->back.pos_rab.x >= data->player.play_pos.x - HITBOX
	  && data->back.pos_rab.x < data->player.play_pos.x))
    printf("\nYOU KILLED THE RABBIT\n");
}

void			anim_attck(t_data *data)
{
  t_bunny_position	pos;

  printf("\n##RABBIT POSITIONS##\nON SCREEN = x -> %d && y -> %d\n\n"
	 , data->back.pos_rab.x, data->back.pos_rab.y);
  data->player.wait++;
  if (data->player.wait % 3 == 0)
    data->player.timatt++;
  data->player.attck->clip_x_position = (data->player.timatt % 12) * 130;
  data->player.attck->clip_width = 130;
  pos.x = data->player.play_pos.x - 30 + data->player.attck_pos.x;
  pos.y = data->player.play_pos.y - 37;
  bunny_blit(&data->window->buffer,
	     data->player.attck,
	     &pos);
  check_murder(data);
  if (data->player.timatt % 12 > 10)
    {
      data->player.isattack = false;
      data->player.timatt = 0;
    }
}

void	idle_anim(t_data *data)
{
  if (data->player.tim_idle % 3 == 0 && data->player.wait % 40 < 38)
    {
      data->player.stay->clip_x_position = 0;
      data->player.stay->clip_width = 70;
      bunny_blit(&data->window->buffer, data->player.stay,
		 &data->player.play_pos);
      data->player.wait++;
      return ;
    }
  data->player.wait++;
  if (data->player.wait % 6 == 0)
    data->player.tim_idle++;
  data->player.stay->clip_x_position = (data->player.tim_idle % 3) * 70;
  data->player.stay->clip_width = 70;
  bunny_blit(&data->window->buffer, data->player.stay,
	     &data->player.play_pos);
}

void	move_player(t_data *data)
{
  refresh_player_pos(&data->player);
  if (data->player.ismoving == true)
    {
      data->player.wait++;
      if (data->player.wait % 5 == 0)
	data->player.tim++;
      data->player.sprite->clip_x_position = (data->player.tim % 10) * 70;
      data->player.sprite->clip_width = 70;
      bunny_blit(&data->window->buffer,
                 data->player.sprite,
                 &data->player.play_pos);
    }
  else if (!data->player.isattack
	   && !data->player.ismoving)
    idle_anim(data);
  else if (data->player.isattack == true)
    anim_attck(data);
}

void	refresh_player_realpos(t_player *player)
{
  if (player->ismoving && player->stateright)
    player->real_pos.x += 1;
  if (player->ismoving && !player->stateright)
    player->real_pos.x -= 1;
}

void	refresh_player_pos(t_player *player)
{
  if (player->ismoving == true)
    {
      refresh_player_realpos(player);
      if (player->stateright == false
	  && player->play_pos.x > LIMIT_LEFT)
        {
	  player->play_pos.x -= 4;
	  player->onborderleft = false;
	  player->onborderright = false;
	}
      if (player->stateright == true
      	  && player->play_pos.x < LIMIT_RIGHT)
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
  printf("\n##PLAYER POSITIONS##\nREAL = x -> %d && y -> %d\n\
ON SCREEN = x -> %d && y -> %d\n\n", player->real_pos.x,
	 player->real_pos.y, player->play_pos.x,
	 player->play_pos.y);
}

void	check_player_movement(t_data *data, t_bunny_keysym keysym,
                              t_bunny_event_state state)
{
  if (keysym == BKS_RIGHT && state == GO_DOWN
      && data->player.stateright == false)
    {
      rotate_player_right(&data->player);
      data->player.ismoving = true;
    }
  else if (keysym == BKS_RIGHT && state == GO_DOWN)
    data->player.ismoving = true;
  if (keysym == BKS_LEFT && state == GO_DOWN
      && data->player.stateright == true)
    {
      rotate_player_left(&data->player);
      data->player.ismoving = true;
    }
  else if (keysym == BKS_LEFT && state == GO_DOWN)
    data->player.ismoving = true;
  if ((keysym == BKS_LEFT || keysym == BKS_RIGHT)
      && state == GO_UP)
    data->player.ismoving = false;
  if (keysym == BKS_SPACE && state == GO_DOWN)
    {
      data->player.isattack = true;
      data->player.ismoving = false;
    }
}
