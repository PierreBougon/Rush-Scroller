/*
** scale.c for scale in /home/duhieu_b/infographie/gfx_scroller
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Mar 20 15:56:09 2016 benjamin duhieu
** Last update Sun Mar 20 22:06:56 2016 marc brout
*/

#include "mega.h"

void	rotate_picture(t_data *data)
{
  if (data->scale == 0)
    data->tmpx = data->back.pos_rab.x;
  data->back.rabbit->rotation =
    (int)(data->back.rabbit->rotation + 1) % 360;
}

void	no_rotate_picture(t_data *data)
{
  data->back.rabbit->rotation =
    (int)(data->back.rabbit->rotation - data->scale * 100) % 360;
  data->back.pos_rab.y = 300;
  data->back.pos_rab.x = data->tmpx;
}

void	scale_picture(t_data *data)
{
  data->back.rabbit->scale.x += 0.01;
  data->back.rabbit->scale.y += 0.01;
  data->scale += 0.01;
}

void	no_scale(t_data *data)
{

  data->back.rabbit->scale.x -= data->scale;
  data->back.rabbit->scale.y -= data->scale;
}
