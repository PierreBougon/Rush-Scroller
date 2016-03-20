/*
** check_pos.c for check_pos in /infographie/gfx_scroller/src
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sat Mar 19 16:26:36 2016 benjamin duhieu
** Last update Sun Mar 20 22:03:52 2016 marc brout
*/

#include "mega.h"

void	check_on_my_right(t_data *d)
{
  if (d->back.pos_rab.x <= -d->back.rabbit->clip_width)
    {
      d->back.pos_rab.x =
	rand() % d->back.mount->clip_width + d->back.back->clip_width;
      d->kill = 0;
    }
  if (d->back.pos_tree.x <= -d->back.tree->clip_width)
    d->back.pos_tree.x =
      rand() % d->back.back->clip_width + d->back.back->clip_width;
  if (d->back.pos_tree2.x <= -(d->back.tree2->clip_width * 3))
    d->back.pos_tree2.x =
      rand() % d->back.back->clip_width + d->back.back->clip_width;
  if (d->back.pos_fence.x <= -d->back.fence->clip_width)
    d->back.pos_fence.x =
      rand() % d->back.mount->clip_width + d->back.back->clip_width;
  if (d->back.pos_mount.x <= -d->back.mount->clip_width)
    d->back.pos_mount.x = d->back.back->clip_width;
  if (d->back.pos_mount2.x <= -d->back.mount->clip_width)
    d->back.pos_mount2.x = d->back.back->clip_width;
}

void	check_on_my_left(t_data *d)
{
  if (d->back.pos_fence.x <= -d->back.fence->clip_width)
    d->back.pos_fence.x =
      rand() % d->back.mount->clip_width + d->back.back->clip_width;
  if (d->back.pos_tree.x <= -d->back.tree->clip_width)
    d->back.pos_tree.x =
      rand() % d->back.back->clip_width + d->back.back->clip_width;
  if (d->back.pos_tree2.x <= -(d->back.tree2->clip_width * 3))
    d->back.pos_tree2.x =
      rand() % d->back.back->clip_width + d->back.back->clip_width;
  if (d->back.pos_mount.x >= d->back.mount->clip_width)
    d->back.pos_mount.x = -d->back.mount->clip_width;
  if (d->back.pos_mount2.x >= d->back.mount->clip_width)
    d->back.pos_mount2.x = -d->back.mount->clip_width;
}
