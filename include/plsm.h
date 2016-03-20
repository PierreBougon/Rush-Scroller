/*
** icnd.h for  in /home/bougon_p/rendu/gfx_incendie/include
**
** Made by Pierre Bougon
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Dec  4 19:45:28 2015 Pierre Bougon
** Last update Sun Mar 20 18:35:27 2016 bougon_p
*/

#ifndef PLSM_H_
# define PLSM_H_

typedef struct		s_plsm
{
  t_bunny_pixelarray	*pixarray;
  t_color      		*colorarray;
  unsigned int		move;
  double		modif;
  double		zoom;
}			t_plsm;

int	draw_plasma(t_plsm *);
void	print_colorarray(t_color *);
int	init_color(int, t_color *);
int	set_plasma(t_plsm *);
int	set_colorarray_plasma(t_color *);
int	set_project(t_plsm *);
int	set_base(t_plsm *);

#endif /* !PLSM_H_ */
