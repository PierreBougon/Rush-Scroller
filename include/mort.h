/*
** mort.h for colle
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Wed Jan  6 23:43:10 2016 marc brout
** Last update Sat Mar 19 23:45:42 2016 marc brout
*/

#ifndef MORT_H_
# define MORT_H_

# include "lapin.h"

typedef struct		s_mort
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*temp;
  int			col;
  int			turn;
}			t_mort;

void my_back_mort(t_bunny_pixelarray *);
void decrem(t_mort *);
void aff_mort(t_mort *, char *);
t_bunny_response my_key(t_bunny_event_state,
			t_bunny_keysym,
			void *);
t_bunny_response main_loop(void *);

#endif /* !MORT_H_ */
