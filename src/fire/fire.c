/*
** fire.c for rush
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Dec  4 21:01:01 2015 marc brout
** Last update Sat Mar 19 23:03:36 2016 marc brout
*/

#include "fire.h"

void		calc_whole_pix(t_fire *fire)
{
  int		y;

  y = HEIGHT;
  while (y > 3)
    {
      calc_next_line(fire, y);
      y -= 3;
    }
}

void		calc_next_line(t_fire *fire, int y)
{
  int		x;
  char		left;
  char		right;
  char		bot;
  int		decal;

  x = -1;
  while (++x < (WIDTH - 1))
    {
      decal = (x) ? 1 : 0;
      left = (x) ? fire->feu->tab[y][x - 1] : 0;
      right = (x < WIDTH) ? fire->feu->tab[y][x + 1] : 0;
      bot = fire->feu->tab[y + 1][x];
      fire->feu->tab[y - 2][x] = ((left + right + bot +
				   fire->feu->tab[y - 1][x]) * 20) / 82;
      fire->feu->tab[y - 3][x + decal] = (fire->feu->tab[y - 1][x] *
					  1000) / 962;
      fire->feu->tab[y - 1][x - decal] = (fire->feu->tab[y - 2][x] *
					  10000) / 9796;
    }
}

void		rand_bottom(t_fire *fire)
{
  int		y;
  int		x;
  int		z;

  y = HEIGHT + 2;
  while (--y > (HEIGHT - 1))
    {
      x = -1;
      while (++x < WIDTH)
	{
	  fire->feu->tab[y][x] = rand() % 128;
	  if (!fire->feu->tab[y][x])
	    {
	      z = -1;
	      while (++x < WIDTH && ++z < (rand() % 100))
		fire->feu->tab[y][x] = 0;
	    }
	}
    }
}

void		color_next_pix(t_color *pal, int col, int *deb, int *fin)
{
  while	(*deb < *fin)
    {
      pal[*deb] = pal[*deb - 1];
      if (*deb != (*fin - 1))
	pal[*deb].argb[col] += 8;
      else
	pal[*deb].argb[col] = 255;
      *deb += 1;
    }
}

/* int			main() */
/* { */
/*   t_fire		fire; */
/*   t_feu			tfeu; */

/*   fire.feu = &tfeu; */
/*   set_palette(&fire); */
/*   if (init_struct(fire.feu)) */
/*     return (1); */
/*   my_fire_aff(&fire); */
/*   free_fire(fire.feu->tab); */
/*   return (0); */
/* } */
