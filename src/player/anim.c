/*
** anim.c for ANIMS in /home/bougon_p/rendu/gfx_scroller
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Mar 20 11:58:02 2016 bougon_p
** Last update Sun Mar 20 22:08:31 2016 marc brout
*/

#include "mega.h"

void			anim_attck(t_data *data)
{
  t_bunny_position      pos;

  data->player.wait++;
  if (data->player.wait % 3 == 0)
    data->player.timatt++;
  data->player.attck->clip_x_position =
    (data->player.timatt % 12) * 130;
  data->player.attck->clip_width = 130;
  pos.x = data->player.play_pos.x - 15 + data->player.attck_pos.x;
  pos.y = data->player.play_pos.y - 39;
  bunny_blit(&data->window->buffer,
             data->player.attck,
             &pos);
  if (data->player.timatt % 12 == 7)
    check_murder(data);
  if (data->player.timatt % 12 > 10)
    {
      data->player.isattack = false;
      data->player.timatt = 0;
    }
}

void	idle_anim(t_data *data)
{
  if (data->player.tim_idle % 3 == 0 && data->player.wait % 20 < 18)
    {
      data->player.play_pos.y -= 5;
      data->player.stay->clip_x_position = 0;
      data->player.stay->clip_width = 70;
      bunny_blit(&data->window->buffer, data->player.stay,
                 &data->player.play_pos);
      data->player.wait++;
      data->player.play_pos.y += 5;
      return ;
    }
  data->player.wait++;
  if (data->player.wait % 8 == 0)
    data->player.tim_idle++;
  data->player.play_pos.y -= 5;
  data->player.stay->clip_x_position = (data->player.tim_idle % 3) * 70;
  data->player.stay->clip_width = 70;
  bunny_blit(&data->window->buffer, data->player.stay,
             &data->player.play_pos);
  data->player.play_pos.y += 5;
}


/*
** Main function for animation of player
** Choose the right sprite sheep
** Choose the right sprite in the sprite sheep
*/
void	move_player(t_data *data)
{
  refresh_player_pos(&data->player);
  if (data->player.ismoving == true)
    {
      data->player.wait++;
      if (data->player.wait % 5 == 0)
        data->player.tim++;
      data->player.sprite->clip_x_position =
	(data->player.tim % 10) * 70;
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
