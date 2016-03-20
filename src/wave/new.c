/*
** new.c for colle
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Thu Jan  7 00:32:10 2016 marc brout
** Last update Thu Jan 14 03:02:51 2016 marc brout
*/
#include <math.h>
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
  rohan->sin = (sin(rohan->turn / 5.55 + (x * M_PI / 360)) * 360 / M_PI) / 2;
}

void			copy(t_rohan *rohan)
{
  int			i;
  int			j;
  int			k;
  int			l;
  unsigned int		*pixels;
  unsigned int		*tmpixels;

  l = -1;
  i = rohan->pix->clipable.clip_width;
  pixels = (unsigned int *)rohan->pix->pixels;
  tmpixels = (unsigned int *)rohan->temp->pixels;
  while (++l < rohan->pix->clipable.clip_width)
    {
      k = -1;
      j = rohan->pix->clipable.clip_height;
      decal(rohan, i);
      while (++k < rohan->pix->clipable.clip_height)
	{
	  tmpixels[(j + (int)rohan->sin) *
		   rohan->temp->clipable.clip_width + i]
	    = pixels[k * rohan->pix->clipable.clip_width + l];
	  j++;
	}
      i++;
    }
}
