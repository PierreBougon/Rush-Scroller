/*
** fire.h for rush
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Dec  4 21:09:30 2015 marc brout
** Last update Sat Mar 19 23:02:01 2016 marc brout
*/

#ifndef FIRE_H_
# define FIRE_H_

# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <lapin.h>
# include <math.h>

# define COLOR_BACK BLACK
# define WIDTH 1280
# define HEIGHT 1024
# define PALETTE 128

typedef struct		s_feu
{
  t_color		pal[PALETTE];
  char			**tab;
}			t_feu;

typedef struct		s_fire
{
  t_feu			*plasma;
  t_feu			*feu;
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_loop		ml;
  unsigned int		decal;
  char			up;
}			t_fire;

t_bunny_response main_loop(void *);
t_bunny_response main_loop_plasma(void *);
t_bunny_response my_key(t_bunny_event_state,
			t_bunny_keysym, void *);
void set_palette(t_fire *);
int init_struct(t_feu *);
void free_fire(char **);
void free_plasma(char **);
void color_next_pix(t_color *, int, int *, int *);
void rand_bottom(t_fire *);

void transfer_color(t_fire *, t_feu *);
void transfer_color_plasma(t_fire *, t_feu *);
void calc_next_line(t_fire *, int);
void calc_whole_pix(t_fire *);
void calc_plasma(t_fire *);
void my_fire_aff(t_fire *);
void my_plasma_aff(t_fire *);
void my_fire_back(t_bunny_pixelarray *);
void my_plasma_back(t_bunny_pixelarray *);
void set_palette_plasma(t_fire *);
void color_sub_plasma(t_color *, int, int *);
void color_add_plasma(t_color *, int, int *);

#endif /* !FIRE_H_ */
