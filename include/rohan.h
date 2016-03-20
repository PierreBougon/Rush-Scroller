/*
** rohan.h for colle
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Wed Jan  6 23:43:10 2016 marc brout
** Last update Sun Mar 20 22:57:46 2016 marc brout
*/

#ifndef ROHAN_H_
# define ROHAN_H_

# include "lapin.h"

typedef struct		s_rohan
{
  t_bunny_window	*win;
  t_bunny_position	pos_play;
  t_bunny_position	pos_quit;
  t_bunny_pixelarray	*play;
  t_bunny_pixelarray	*quit;
  t_bunny_pixelarray	*temp;
  int			turn;
  double		sin;
}			t_rohan;

void my_back(t_bunny_pixelarray *);
void copy_normal(t_bunny_pixelarray *, t_bunny_pixelarray *,
		 t_bunny_position *);
void copy(t_bunny_pixelarray *, t_bunny_pixelarray *,
	  t_rohan *, t_bunny_position *);
void aff_rohan(t_rohan *, char *);
t_bunny_response my_key(t_bunny_event_state,
			t_bunny_keysym,
			void *);
t_bunny_response main_loop(void *);

#endif /* !ROHAN_H_ */
