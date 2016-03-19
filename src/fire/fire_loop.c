/*
** fire_loop.c for rush
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Dec  4 21:02:55 2015 marc brout
** Last update Sun Dec  6 11:41:36 2015 marc brout
*/

#include "fire.h"

void		transfer_color(t_fire *fire, t_feu *feu)
{
  int		x;
  int		y;
  t_color	*pixels;
  int		flash;

  y = -1;
  pixels = fire->pix->pixels;
  flash = rand() % 150;
  while (++y < HEIGHT)
    {
      x = -1;
      while (++x < WIDTH)
	{
	  if (feu->tab[y][x] &&
	      feu->tab[y][x] < 117 && flash < 1)
	    feu->tab[y][x] += rand() % 10;
	  pixels[x + y * WIDTH] = feu->pal[(int)feu->tab[y][x]];
	}
    }
}

t_bunny_response	my_key(t_bunny_event_state state,
			       t_bunny_keysym keysym,
			       void *data)
{
  if (keysym == BKS_ESCAPE)
    if (state == GO_DOWN)
      {
	(void)data;
	return (EXIT_ON_SUCCESS);
      }
  return (GO_ON);
}

t_bunny_response	main_loop(void *data)
{
  t_fire		*fire;

  fire = data;
  my_fire_back(fire->pix);
  rand_bottom(fire);
  calc_whole_pix(fire);
  transfer_color(fire, fire->feu);
  bunny_blit(&fire->win->buffer, &fire->pix->clipable, NULL);
  bunny_display(fire->win);
  return (GO_ON);
}
