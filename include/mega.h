/*
** mega.h for MEGA in /home/bougon_p/rendu/gfx_scroller
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Mar 18 20:39:34 2016 bougon_p
** Last update Sat Mar 19 16:37:44 2016 benjamin duhieu
*/

#ifndef mega_h_
# define mega_h_

# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include "lapin.h"

# define UNUSED __attribute__((__unused__))

# define WIN_WIDTH 640
# define WIN_HEIGHT 480
# define LIMIT_RIGHT WIN_WIDTH / 2 + 50
# define LIMIT_LEFT WIN_WIDTH / 2 - 50
# define FLOOR 332

# define SKY 0xFF705A4E
# define GREY 0xFF252525

typedef	struct		s_player
{
  t_bunny_picture	*sprite;
  int			wait;
  int			tim;
  t_bunny_position	play_pos;
  t_bunny_position	real_pos;
  bool			stateright;

  bool			ismoving;
  bool			onborderright;
  bool			onborderleft;
}			t_player;

typedef struct		s_back
{
  t_bunny_position	pos_mount;
  t_bunny_position	pos_mount2;
  t_bunny_position	pos_sky;
  t_bunny_position	pos_sky2;
  t_bunny_position	pos_rab;
  t_bunny_position	pos_tree;
  t_bunny_position	pos_tree2;
  t_bunny_position	pos_fence;
  t_bunny_position	pos_grass[3];
  t_bunny_position	pos_grass2[3];
  t_bunny_position	pos_ground;
  t_bunny_position	pos_ground2;
  t_bunny_position	pos_gui;
  t_bunny_picture	*grass[3];
  t_bunny_picture	*grass2[3];
  t_bunny_picture	*ground;
  t_bunny_picture	*ground2;
  t_bunny_picture	*fence;
  t_bunny_picture	*rabbit;
  t_bunny_picture	*tree;
  t_bunny_picture	*tree2;
  t_bunny_picture	*mount;
  t_bunny_picture	*mount2;
  t_bunny_picture	*sky;
  t_bunny_picture	*sky2;
  t_bunny_picture	*back;
  t_bunny_picture	*gui;
}			t_back;

typedef	struct		s_data
{
  t_bunny_window	*window;
  t_bunny_pixelarray	*pixarray;
  t_player		player;
  t_back		back;
}			t_data;

void	scroll(t_bunny_picture *);


/*
** BACKGROUND
*/
void	draw_bg(t_data *);
void	draw_sky(t_data *);
/*
** Players functions
*/
int	init_sprites(t_data *);
int	init_player(t_data *);
void	check_on_my_left(t_data *);
void	check_on_my_right(t_data *);
void	draw_bg(t_data *);
void	draw_grass(t_data *);
void	draw_left(t_data *);
void	draw_right(t_data *);
void	draw_sky(t_data *);
void	grass_move(t_data *, int);
void	move_player(t_data *);
void	rotate_player_left(t_player *);
void	rotate_player_right(t_player *);
void	refresh_player_pos(t_player *);
void	check_player_movement(t_data *, t_bunny_keysym, t_bunny_event_state);

#endif /* !mega_h_  */
