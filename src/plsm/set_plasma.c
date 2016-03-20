/*
** set_plasma.c for plasma in /home/bougon_p/rendu/gfx_incendie
**
** Made by Pierre Bougon
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Dec  6 19:31:33 2015 Pierre Bougon
** Last update Sun Mar 20 18:20:44 2016 bougon_p
*/

#include "mega.h"

unsigned int	set_plaspix(float x, float y, t_plsm *data)
{
  return (((63.0 + (63.0 * sin(x / 16.0))
	    + 63.0 + (63.0 * sin(y / data->zoom))
	    + 63.0 + (63 * sin((x + y + data->move) / data->modif))
	    + 63.0 + (63 * sin(sqrt(x * x + y * y) / 2))) / 7));
}

int			draw_plasma(t_plsm *data)
{
  float			i;
  float			j;
  int			color;
  t_bunny_position	pos;

  i = 0;
  j = WIN_HEIGHT;
  while (j >= 0)
    {
      while (i < WIN_WIDTH)
	{
	  pos.x = i;
	  pos.y = j;
	  color = set_plaspix(i, j, data);
	  tekpixel(data->pixarray, &pos, &data->colorarray[color]);
	  i++;
	}
      i = 0;
      j--;
    }
  return (0);
}
