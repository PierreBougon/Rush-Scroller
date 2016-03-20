/*
** fondu.c for fondu in /home/duhieu_b/infographie/gfx_scroller
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Mar 20 20:43:50 2016 benjamin duhieu
** Last update Sun Mar 20 21:58:09 2016 bougon_p
*/

#include "mega.h"

void		put_pixel(int i, int j, int *ok, t_data *data)
{
  t_color	*pixel;
  int		count;

  pixel = (t_color *)data->pixarray->pixels;
  count = j + i * data->pixarray->clipable.clip_width;
  if (pixel[count].argb[0] > 0)
    pixel[count].argb[0] -= 1;
  if (pixel[count].argb[1] > 0)
    pixel[count].argb[1] -= 1;
  if (pixel[count].argb[2] > 0)
    pixel[count].argb[2] -= 1;
  if (!*ok)
    return ;
  if (pixel[count].argb[0] > 0 ||
      pixel[count].argb[1] > 0 ||
      pixel[count].argb[2] > 0)
    {
      *ok = 0;
    }
  else
    *ok = 1;
}

void		fondu(t_data *data)
{
  int		i;
  int		j;
  int		ok;

  ok = 1;
  i = -1;
  while (++i < data->pixarray->clipable.clip_height)
    {
      j = -1;
      while (++j < data->pixarray->clipable.clip_width)
	put_pixel(i, j, &ok, data);
    }
  bunny_blit(&data->window->buffer, &data->pixarray->clipable, NULL);
  if (ok)
    data->state.fondu = true;
}
