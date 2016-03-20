/*
** mega.h for MEGA in /home/bougon_p/rendu/gfx_scroller
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Mar 18 20:39:34 2016 bougon_p
** Last update Sun Mar 20 17:46:41 2016 benjamin duhieu
*/

#ifndef mega_h_
# define mega_h_

# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include "lapin.h"
# include "sampler.h"
# include "fire.h"
# include "text.h"
# include "mort.h"
# include "rohan.h"

# define UNUSED __attribute__((__unused__))

# define WIN_WIDTH 640
# define WIN_HEIGHT 480
# define LIMIT_RIGHT WIN_WIDTH / 2 + 150
# define LIMIT_LEFT WIN_WIDTH / 2 - 150
# define FLOOR 332
# define HITBOX 100

# define SKY 0xFF705A4E
# define GREY 0xFF252525

typedef	struct		s_player
{
  t_bunny_picture	*sprite;
  t_bunny_picture	*stay;
  t_bunny_picture	*attck;
  int			wait;
  int			tim;
  int			tim_idle;
  int			timatt;
  t_bunny_position	attck_pos;
  t_bunny_position	play_pos;
  t_bunny_position	real_pos;
  bool			stateright;
  bool			ismoving;
  bool			onborderright;
  bool			onborderleft;
  bool			isattack;
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
  t_bunny_position	pos_gui;
  t_bunny_picture	*grass;
  t_bunny_picture	*grass2;
  t_bunny_picture	*fence;
  t_bunny_picture	*rabbit;
  t_bunny_picture	*tree;
  t_bunny_picture	*tree2;
  t_bunny_picture	*mount;
  t_bunny_picture	*sky;
  t_bunny_picture	*back;
  t_bunny_picture	*gui;
}			t_back;

typedef struct		s_state
{
  bool			menu;
  bool			game;
  bool			end;
}			t_state;

typedef struct		s_menu
{
  t_bunny_pixelarray	*scr;
  t_bunny_pixelarray	*png;
  t_bunny_position	pos;
  t_text		*txt;
  t_fire		*fire;
  double		move;
  int			count;
  t_mort		*mort;
  t_rohan		*rohan;
  bool			start;
}			t_menu;

typedef	struct		s_data
{
  t_bunny_window	*window;
  t_bunny_pixelarray	*pixarray;
  t_bunny_effect	*saber;
  t_bunny_effect	*death;
  t_sample		*samples[NB_SAMPLES];
  char			*str;
  double		scale;
  int			tmpx;
  int			letters;
  int			curmusic;
  int			change;
  int			kill;
  t_player		player;
  t_back		back;
  t_state		state;
  t_menu		menu;
}			t_data;

void	scroll(t_bunny_picture *);

/*
** init_sampler.c
*/

void	free_sampler(t_data *data);
int	init_sampler(t_data *data);
void	sampler_keys(t_data *data,
		     t_bunny_keysym keysym);

/*
** DISPLAY
*/
void	disp_game(t_data *);
void	disp_menu(t_data *);
void	disp_end(t_data *);

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
void	init_tree(t_data *);
void	move_player(t_data *);
void	rotate_player_left(t_player *);
void	rotate_player_right(t_player *);
void	refresh_player_pos(t_player *);
void	check_player_movement(t_data *,
			      t_bunny_keysym,
			      t_bunny_event_state);
/*
** Disp text: tet.c
*/

t_text	*char_to_list(char *);
t_text	*chk_chr(t_text *, char);
void	disalpha(char *);
void	disp_text(t_text *, t_menu *, char *);
void	fill_list(t_text *, char, int);
void	put_space();
void	put_on_screen(t_menu *, t_text *, int, int);

/*
** Disp text: tet.c
*/

void	no_scale(t_data *);
void	no_rotate_picture(t_data *);
void	scale_picture(t_data *);
void	rotate_picture(t_data *);

/*
** OTHERS
*/
void	delete_all_clipables(t_data *);
int	init_var(t_data *);
int	init_fire(t_data *);


#endif /* !mega_h_  */
