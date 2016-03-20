/*
** main.c for MAIN in /home/bougon_p/rendu/gfx_scroller
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Mar 18 20:25:37 2016 bougon_p
** Last update Sun Mar 20 17:48:55 2016 benjamin duhieu
*/

#include <string.h>
#include "mega.h"

t_bunny_response	button_key(t_bunny_event_state state,
                                t_bunny_keysym keysym, void *_data)
{
  t_data		*data;

  data = _data;
  if (keysym == BKS_ESCAPE && state == GO_DOWN)
    return (EXIT_ON_SUCCESS);
  if (data->state.game)
    check_player_movement(data, keysym, state);
  if (data->state.menu && data->menu.start &&
      keysym == BKS_RETURN && state == GO_DOWN)
    {
      data->state.menu = false;
      data->state.game = true;
    }
  if (keysym == BKS_Z && state == GO_DOWN)
    {
      rotate_picture(data);
      scale_picture(data);
    }
  if (data->scale > 0 && keysym == BKS_Z && state == GO_UP)
    {
      no_scale(data);
      no_rotate_picture(data);
      data->scale = 0;
    }
  if (state == GO_DOWN)
    sampler_keys(data, keysym);
  return (GO_ON);
}

t_bunny_response	click_actions(UNUSED t_bunny_event_state state,
                                      UNUSED t_bunny_mousebutton button,
				      void *_data)
{
  UNUSED t_data		*data;

  data = _data;
  return (GO_ON);
}

t_bunny_response	mainloop(void *_data)
{
  t_data                *data;

  data = _data;
  sampler(data->samples[data->curmusic], &data->change);
  if (data->state.menu)
    disp_menu(data);
  else if (data->state.game)
    disp_game(data);
  else if (data->state.end)
    disp_end(data);
  bunny_display(data->window);
  return (GO_ON);
}

int		main()
{
  t_data	data;

  srand(time(NULL));
  bunny_set_maximum_ram(20000000);
  data.str = strdup(PRESENTATION);
  data.letters = strlen(data.str) * 34;
  data.scale = 0.0;
  if (!(data.window = bunny_start(WIN_WIDTH, WIN_HEIGHT, 0, "MEGAMAN")) ||
      !(data.pixarray = bunny_new_pixelarray(WIN_WIDTH, WIN_HEIGHT)))
    return (1);
  if (init_var(&data) == 1)
    return (1);
  bunny_set_loop_main_function(mainloop);
  bunny_set_key_response(button_key);
  bunny_set_click_response(click_actions);
  bunny_loop(data.window, 60, &data);
  delete_all_clipables(&data);
  free_sampler(&data);
  bunny_stop(data.window);
  return (0);
}
