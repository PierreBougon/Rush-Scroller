/*
** new.c for colle
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Jan  7 00:32:10 2016 marc brout
** Last update Sun Mar 20 23:21:12 2016 marc brout
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

void			decrem_suite(t_decrem *d, t_mort *mort)
{
  d->pos2 = d->x + (d->y * WIDTH);
  if (d->x < mort->pix->clipable.clip_width)
    {
      d->imgpixels[d->pos2].argb[mort->turn % 3]
	+= -d->pixels[d->pos].argb[0];
      d->imgpixels[d->pos2].argb[(mort->turn + 1) % 3]
	+= -d->pixels[d->pos].argb[1];
      d->imgpixels[d->pos2].argb[(mort->turn + 2) % 3]
	+= -d->pixels[d->pos].argb[2];
    }
}

void			decrem(t_mort *mort)
{
  t_decrem		d;

  d.pixels = mort->pix->pixels;
  d.imgpixels = mort->temp->pixels;
  d.y = -1;
  while (++d.y < HEIGHT)
    {
      d.x = -1;
      while (++d.x < WIDTH)
	{
	  d.pos = d.x + (d.y * mort->pix->clipable.clip_width);
	  if (d.pixels[d.pos].full)
	    if (d.pixels[d.pos].argb[1] >= mort->col)
	      decrem_suite(&d, mort);
	}
    }
}
