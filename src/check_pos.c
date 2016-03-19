/*
** check_pos.c for check_pos in /home/duhieu_b/infographie/gfx_scroller/src
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sat Mar 19 16:26:36 2016 benjamin duhieu
** Last update Sat Mar 19 18:43:51 2016 benjamin duhieu
*/

#include "mega.h"

void	check_on_my_right(t_data *data)
{
  if (data->back.pos_rab.x <= -data->back.rabbit->clip_width)
    {
      data->back.pos_rab.x =
	rand() % data->back.mount->clip_width + data->back.back->clip_width;
      data->kill = 0;
    }
  if (data->back.pos_tree.x <= -data->back.tree->clip_width)
    data->back.pos_tree.x =
      rand() % data->back.back->clip_width + data->back.back->clip_width;
  if (data->back.pos_tree2.x <= -(data->back.tree2->clip_width * 3))
    data->back.pos_tree2.x =
      rand() % data->back.back->clip_width + data->back.back->clip_width;
  if (data->back.pos_fence.x <= -data->back.fence->clip_width)
    data->back.pos_fence.x =
      rand() % data->back.mount->clip_width + data->back.back->clip_width;
  if (data->back.pos_mount.x <= -data->back.mount->clip_width)
    data->back.pos_mount.x = data->back.back->clip_width;
  if (data->back.pos_mount2.x <= -data->back.mount2->clip_width)
    data->back.pos_mount2.x = data->back.back->clip_width;
}

void	check_on_my_left(t_data *data)
{
  /* if (data->back.pos_rab.x <= -data->back.rabbit->clip_width) */
  /*   data->back.pos_rab.x = */
  /*     rand() % data->back.mount->clip_width + data->back.back->clip_width; */
  if (data->back.pos_fence.x <= -data->back.fence->clip_width)
    data->back.pos_fence.x =
      rand() % data->back.mount->clip_width + data->back.back->clip_width;
  if (data->back.pos_tree.x <= -data->back.tree->clip_width)
    data->back.pos_tree.x =
      rand() % data->back.back->clip_width + data->back.back->clip_width;
  if (data->back.pos_tree2.x <= -(data->back.tree2->clip_width * 3))
    data->back.pos_tree2.x =
      rand() % data->back.back->clip_width + data->back.back->clip_width;
  if (data->back.pos_mount.x >= data->back.mount->clip_width)
    data->back.pos_mount.x = -data->back.mount->clip_width;
  if (data->back.pos_mount2.x >= data->back.mount2->clip_width)
    data->back.pos_mount2.x = -data->back.mount2->clip_width;
}
