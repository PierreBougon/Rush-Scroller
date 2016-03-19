/*
** new.c for colle
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Jan  7 00:32:10 2016 marc brout
** Last update Sat Mar 19 23:45:22 2016 marc brout
*/

#include "mort.h"

void			my_back_mort(t_bunny_pixelarray *pix)
{
  int			i;
  unsigned int		*pixels;
  int			total;

  total = pix->clipable.clip_width * pix->clipable.clip_height;
  pixels = pix->pixels;
  i = -1;
  while (++i < total)
    pixels[i] = BLACK;
}

void			decrem(t_mort *mort)
{
  int			i;
  t_color		*pixels;
  t_color		*imgpixels;
  int			total;

  total = mort->pix->clipable.clip_width *
    mort->pix->clipable.clip_height;
  pixels = mort->pix->pixels;
  imgpixels = mort->temp->pixels;
  i = -1;
  while (++i < total)
    {
      if (pixels[i].argb[1] >= mort->col)
	imgpixels[i].argb[mort->turn % 3] = -pixels[i].argb[1];
    }
}
