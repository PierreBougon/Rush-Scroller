/*
** new.c for colle
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Jan  7 00:32:10 2016 marc brout
** Last update Sun Mar 20 20:32:09 2016 benjamin duhieu
*/

#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include "rohan.h"

void			my_back(t_bunny_pixelarray *pix)
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

void			decal(t_rohan *rohan, int x)
{
  rohan->sin = (sin(rohan->turn / 10.0 + (x * M_PI / 400)) * 360 / M_PI) / 4;
}

void			copy_normal(t_bunny_pixelarray *scr, t_bunny_pixelarray *png,
				    t_bunny_position *pos)
{
 int			k;
  int			l;
  unsigned int		*pixels;
  unsigned int		*tmpixels;

  l = -1;
  pixels = (unsigned int *)png->pixels;
  tmpixels = (unsigned int *)scr->pixels;
  while (++l < png->clipable.clip_height)
    {
      k = -1;
      while (++k < png->clipable.clip_width)
	{
	  tmpixels[(pos->x + k) + (pos->y + l) * scr->clipable.clip_width]
	    = pixels[k + l * png->clipable.clip_width];
	}
    }
}

void			copy(t_bunny_pixelarray *scr, t_bunny_pixelarray *png,
			     t_rohan *rohan, t_bunny_position *pos)
{
  int			k;
  int			l;
  unsigned int		*pixels;
  unsigned int		*tmpixels;

  l = -1;
  pixels = (unsigned int *)png->pixels;
  tmpixels = (unsigned int *)scr->pixels;
  while (++l < png->clipable.clip_width)
    {
      k = -1;
      decal(rohan, l);
      while (++k < png->clipable.clip_height)
	{
	  tmpixels[(pos->x + l) + (pos->y + k + (int)rohan->sin) *
		   scr->clipable.clip_width]
	    = pixels[l + k * png->clipable.clip_width];
	}
    }
}
