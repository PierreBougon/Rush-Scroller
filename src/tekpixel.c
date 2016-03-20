/*
** tekpixel.c for PIX in /home/bougon_p/rendu/gfx_scroller
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Mar 20 14:55:19 2016 bougon_p
** Last update Sun Mar 20 14:58:30 2016 bougon_p
*/

#include "mega.h"

void		tekpixel(t_bunny_pixelarray *pix, t_bunny_position *pos,
                         t_color *color)
{
  t_color	*col;

  col = (t_color*)pix->pixels +
    pos[0].x + pos[0].y * pix->clipable.clip_width;
  col->full = color->full;
}
