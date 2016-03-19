/*
** rohan.h for colle 
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Wed Jan  6 23:43:10 2016 marc brout
** Last update Wed Jan 13 22:00:10 2016 marc brout
*/

#ifndef ROHAN_H_
# define ROHAN_H_

# include "lapin.h"

typedef struct		s_rohan
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*temp;
  int		        decal;
  int			turn;
  double		sin;
}			t_rohan;

void my_back(t_bunny_pixelarray *);
void copy(t_rohan *);
void aff_rohan(t_rohan *, char *);
t_bunny_response my_key(t_bunny_event_state,
			t_bunny_keysym,
			void *);
t_bunny_response main_loop(void *);

#endif /* !ROHAN_H_ */
