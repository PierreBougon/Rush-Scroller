/*
** fire_fdf.c for rush
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Thu Nov 19 09:49:45 2015 marc brout
** Last update Sun Dec  6 11:57:45 2015 marc brout
*/

#include "fire.h"

void			my_fire_back(t_bunny_pixelarray *pix)
{
  int			i;
  unsigned int		*pixels;
  int			total;

  total = WIDTH * HEIGHT;
  pixels = pix->pixels;
  i = -1;
  while (++i < total)
    pixels[i] = BLACK;
}

void			my_fire_aff(t_fire *fire)
{
  t_bunny_key		keyesc;

  keyesc = &my_key;
  fire->ml = &main_loop;
  fire->decal = 0;
  fire->pix = bunny_new_pixelarray(WIDTH, HEIGHT);
  fire->win = bunny_start(WIDTH, HEIGHT, 0, "HIGH WAY TO HELL");
  bunny_set_key_response(keyesc);
  bunny_set_loop_main_function(fire->ml);
  bunny_loop(fire->win, 60, fire);
  bunny_delete_clipable(&fire->pix->clipable);
  bunny_stop(fire->win);
}

void	set_palette(t_fire *fire)
{
  int	i;
  int	ecart;
  int	step;

  i = 0;
  ecart = PALETTE / 4;
  step = ecart;
  fire->feu->pal[i++].full = BLACK;
  color_next_pix(fire->feu->pal, 0, &i, &step);
  step += ecart;
  color_next_pix(fire->feu->pal, 1, &i, &step);
  step += ecart;
  color_next_pix(fire->feu->pal, 2, &i, &step);
  step += ecart;
  i += -1;
  while (++i < step)
    fire->feu->pal[i].full = WHITE;
}

int			init_struct(t_feu *tex)
{
  int			i;
  int			x;

  if ((tex->tab = bunny_malloc(sizeof(char *) *
			       (HEIGHT + 3))) == NULL)
    return (1);
  i = -1;
  while (++i < (HEIGHT + 2))
    {
      if ((tex->tab[i] = bunny_malloc(WIDTH + 1)) == NULL)
	return (1);
      x = -1;
      while (++x < WIDTH + 1)
	tex->tab[i][x] = 0;
    }
  return (0);
}

void		free_fire(char **tab)
{
  int		i;

  i = -1;
  while (++i < (HEIGHT + 2))
    bunny_free(tab[i]);
  bunny_free(tab);
}
