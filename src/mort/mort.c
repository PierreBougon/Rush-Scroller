/*
** mort.c for mort
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Wed Jan  6 23:41:59 2016 marc brout
** Last update Sun Mar 20 22:07:36 2016 marc brout
*/

#include "mort.h"

t_bunny_response	main_loop_mort(void *data)
{
  t_mort		*mort;
  static char		going = 0;

  mort = data;
  my_back_mort(mort->temp);
  decrem(mort);
  bunny_blit(&mort->win->buffer, &mort->temp->clipable, NULL);
  bunny_display(mort->win);
  if (!going)
    {
      mort->col += 1;
      if (mort->col >= 255)
	{
	  mort->turn += 1;
	  going = 1;
	}
    }
  else
    {
      mort->col -= 1;
      if (mort->col <= 0)
	going = 0;
    }
  return (GO_ON);
}

t_bunny_response	my_key_mort(t_bunny_event_state state,
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

void		aff_mort(t_mort *mort, char *img)
{
  t_bunny_key	keyesc;

  keyesc = &my_key_mort;
  if ((mort->pix = bunny_load_pixelarray(img)) == NULL ||
      (mort->temp = bunny_new_pixelarray
       (mort->pix->clipable.clip_width,
	mort->pix->clipable.clip_height)) == NULL ||
      (mort->win = bunny_start(mort->pix->clipable.clip_width,
			       mort->pix->clipable.clip_height,
			       0, "LA MUERTA")) == NULL)
    return ;
  mort->col = 255;
  mort->turn = 1;
  bunny_set_key_response(keyesc);
  bunny_set_loop_main_function(main_loop_mort);
  bunny_loop(mort->win, 60, mort);
  bunny_delete_clipable(&mort->pix->clipable);
  bunny_stop(mort->win);
}
