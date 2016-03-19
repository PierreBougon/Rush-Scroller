/*
** main.c for MAIN in /home/bougon_p/rendu/gfx_scroller
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Mar 18 20:25:37 2016 bougon_p
** Last update Sat Mar 19 15:53:28 2016 benjamin duhieu
*/

#include "mega.h"

t_bunny_response	button_key(t_bunny_event_state state,
                                t_bunny_keysym keysym, void *_data\
				)
{
  t_data		*data;

  data = _data;
  if (keysym == BKS_ESCAPE && state == GO_DOWN)
    return (EXIT_ON_SUCCESS);
  check_player_movement(data, keysym, state);
  return (GO_ON);
}

t_bunny_response	click_actions(UNUSED t_bunny_event_state state,
                                      UNUSED t_bunny_mousebutton button, \
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
  draw_bg(data);
  move_player(data);
  bunny_blit(&data->window->buffer, data->back.fence, &data->back.pos_fence);
    bunny_blit(&data->window->buffer, data->back.tree2, &data->back.pos_tree2);
  bunny_display(data->window);
  return (GO_ON);
}

int		main()
{
  t_data	data;

  srand(time(0));
  if (init_sprites(&data) == 1 || init_player(&data) == 1)
    return (1);
  data.window = bunny_start(WIN_WIDTH, WIN_HEIGHT, 0, "MEGAMAN");
  bunny_set_loop_main_function(mainloop);
  bunny_set_key_response(button_key);
  bunny_set_click_response(click_actions);
  bunny_loop(data.window, 60, &data);
  bunny_delete_clipable(data.back.mount);
  bunny_delete_clipable(data.back.mount2);
  bunny_delete_clipable(data.back.sky);
  bunny_delete_clipable(data.back.sky2);
  bunny_delete_clipable(data.back.gui);
  bunny_delete_clipable(data.back.back);
  bunny_delete_clipable(data.back.grass[0]);
  bunny_delete_clipable(data.player.sprite);
  bunny_stop(data.window);
  return (0);
}
