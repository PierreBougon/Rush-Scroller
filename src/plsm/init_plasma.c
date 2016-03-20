/*
** init_plasma.c for init in /home/bougon_p/rendu/gfx_incendie
**
** Made by Pierre Bougon
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Dec  6 18:03:46 2015 Pierre Bougon
** Last update Sun Mar 20 17:50:02 2016 bougon_p
*/

#include "mega.h"

int	init_plasmacolor(int i, t_color *col)
{
  if (i < 32)
    col->argb[1] = 0 + i * 8;
  else if (i < 64)
    {
      col->argb[1] = 255;
      col->argb[2] = 255 - i * 8;
    }
  else if (i < 96)
    {
      col->argb[0] = 0 + i * 8;
      col->argb[1] = 255;
      col->argb[2] = 0;
    }
  else if (i < 128)
    {
      col->argb[0] = 255;
      col->argb[1] = 255 - i * 8;
      col->argb[2] = 0;
    }
  return (0);
}

int		set_colorarray_plasma(t_color *color)
{
  int           i;
  t_color       col;

  col.argb[0] = 0;
  col.argb[1] = 0;
  col.argb[2] = 255;
  col.argb[3] = 0;
  i = 0;
  while (i < 128)
    {
      init_plasmacolor(i, &col);
      color[i].argb[0] = col.argb[0];
      color[i].argb[1] = col.argb[1];
      color[i].argb[2] = col.argb[2];
      color[i].argb[3] = 0;
      i++;
    }
  return (0);
}
