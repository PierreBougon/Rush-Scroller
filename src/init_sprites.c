/*
** init_sprites.c for MEGAMAN in /home/bougon_p/rendu/gfx_scroller
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Mar 19 00:06:52 2016 bougon_p
** Last update Sat Mar 19 17:37:22 2016 benjamin duhieu
*/

#include "mega.h"

void	final_init(t_data *data)
{
  data->back.pos_grass[0].x = 0;
  data->back.pos_grass[1].x = 0;
  data->back.pos_grass[2].x = 0;
  data->back.pos_grass2[0].x = data->back.grass2[0]->clip_width;
  data->back.pos_grass2[1].x = data->back.grass2[1]->clip_width;
  data->back.pos_grass2[2].x = data->back.grass2[2]->clip_width;
  data->back.tree2->scale.x = 3.0;
  data->back.tree2->scale.y = 3.0;
  data->back.pos_fence.y = 250;
  data->back.fence->scale.y = 2.0;
  data->back.pos_fence.x = rand() %
    (data->back.mount2->clip_width * 2) + data->back.back->clip_width;
}

void	next_init(t_data *data)
{
  data->back.pos_mount.x = 0;
  data->back.pos_mount2.x = data->back.mount2->clip_width;
  data->back.pos_sky.x = 0;
  data->back.pos_sky.y = 0;
  data->back.pos_sky2.x = data->back.sky2->clip_width;
  data->back.pos_sky2.y = 0;
  data->back.pos_mount.y = 40;
  data->back.pos_mount2.y = 40;
  data->back.pos_rab.y = 300;
  data->back.pos_rab.x = rand() % data->back.mount2->clip_width;
  data->back.pos_tree.y = 110;
  data->back.pos_tree.x = rand() % data->back.mount2->clip_width;
  data->back.pos_tree2.y = -200;
  data->back.pos_tree2.x = rand() % data->back.mount2->clip_width;
}

int	init_sprites(t_data *data)
{
  if (!(data->player.sprite = bunny_load_picture("img/sprite.png")) ||
      !(data->back.back = bunny_new_picture(WIN_WIDTH, WIN_HEIGHT)) ||
      !(data->back.gui = bunny_new_picture(WIN_WIDTH, WIN_HEIGHT)) ||
      !(data->back.mount = bunny_load_picture("img/montagnes.png")) ||
      !(data->back.mount2 = bunny_load_picture("img/montagnes.png")) ||
      !(data->back.sky = bunny_load_picture("img/nuages2.png")) ||
      !(data->back.sky2 = bunny_load_picture("img/nuages2.png")) ||
      !(data->back.fence = bunny_load_picture("img/barriere.png")) ||
      !(data->back.rabbit = bunny_load_picture("img/lapin_noir.png")) ||
      !(data->back.tree = bunny_load_picture("img/arbre-V5Z.png")) ||
      !(data->back.tree2 = bunny_load_picture("img/arbre-V5Z.png")) ||
      !(data->back.grass[0] = bunny_load_picture("img/grass.png")) ||
      !(data->back.grass[1] = bunny_load_picture("img/grass.png")) ||
      !(data->back.grass[2] = bunny_load_picture("img/grass.png")) ||
      !(data->back.grass2[0] = bunny_load_picture("img/grass.png")) ||
      !(data->back.grass2[1] = bunny_load_picture("img/grass.png")) ||
      !(data->back.grass2[2] = bunny_load_picture("img/grass.png")) ||
      !(data->player.attck = bunny_load_picture("img/attack.png")))
    return (1);
  next_init(data);
  final_init(data);
  return (0);
}
