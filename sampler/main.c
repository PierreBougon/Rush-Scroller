/*
** main.c for MAIN in /home/bougon_p/rendu/gfx_scroller
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Mar 18 20:25:37 2016 bougon_p
** Last update Sat Mar 19 17:08:13 2016 benjamin duhieu
*/

#include <stdio.h>
#include "mega.h"

t_bunny_response	esc_key(t_bunny_event_state state,
                                t_bunny_keysym keysym,
				void *_data)
{
  t_data		*data;

  data = _data;
  if (state == GO_DOWN)
    {
      if (keysym == BKS_ESCAPE)
	return (EXIT_ON_SUCCESS);
      if (keysym == BKS_P)
	change_music(data->samples, &data->curmusic,
		     &data->change, 1);
      if (keysym == BKS_M)
	change_music(data->samples, &data->curmusic,
		     &data->change, -1);
    }
  return (GO_ON);
}

t_bunny_response	click_actions(UNUSED t_bunny_event_state state,
                                      UNUSED t_bunny_mousebutton button,
				      UNUSED void *_data)
{
  return (GO_ON);
}

t_bunny_response	mainloop(void *_data)
{
  t_data                *data;

  data = _data;
  sampler(data->samples[data->curmusic], &data->change);
  bunny_display(data->window);
  return (GO_ON);
}

int		main()
{
  t_data	data;

  srand(time(0));
  if (!(data.samples[0] = load_bsf(BSF_1, SAMPLE_FOLD)) ||
      !(data.samples[1] = load_bsf(BSF_2, SAMPLE_FOLD)) ||
      !(data.samples[2] = load_bsf(BSF_3, SAMPLE_FOLD)) ||
      !(data.samples[3] = load_bsf(BSF_4, SAMPLE_FOLD)))
    return (1);
  data.window = bunny_start(WIN_WIDTH, WIN_HEIGHT, 0, "DEMO");
  data.curmusic = 0;
  data.change = 0;
  bunny_set_loop_main_function(mainloop);
  bunny_set_key_response(esc_key);
  bunny_set_click_response(click_actions);
  bunny_loop(data.window, 60, &data);
  bunny_stop(data.window);
  return (0);
}
