/*
** text.c for text in /home/duhieu_b/infographie/gfx_scroller/src
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Mar 20 10:03:58 2016 benjamin duhieu
<<<<<<< HEAD
** Last update Sun Mar 20 23:28:02 2016 bougon_p
=======
** Last update Sun Mar 20 23:14:05 2016 benjamin duhieu
>>>>>>> ab572c8335c99da343b72080b6a814e0ad5314e4
*/

#include "mega.h"
#include "text.h"

<<<<<<< HEAD
void		fill_list(t_text *txt, char c, int i)
{
  txt->chr = c;
  txt->col = i % 9;
  txt->row = i / 9;
  txt->next = NULL;
}

t_text		*char_to_list(char *txt)
{
  t_text	*elem;
  t_text	*text;
  int		i;

  if (!(text = bunny_malloc(sizeof(t_text))))
    return (NULL);
  text->next = NULL;
  elem = text;
  i = -1;
  while (txt[++i])
    {
      if (i < 26)
	fill_list(elem, txt[i], i);
      else
	fill_list(elem, txt[i], i + 1);
      if (!(elem->next = bunny_malloc(sizeof(t_text))))
	return (NULL);
      elem = elem->next;
    }
  elem->next = NULL;
  return (text);
}

=======
>>>>>>> ab572c8335c99da343b72080b6a814e0ad5314e4
t_text		*chk_chr(t_text *txt, char c)
{
  t_text	*elem;

  elem = txt;
  while (elem->next->next != NULL && elem->chr != c)
    elem = elem->next;
  if (elem->next->next == NULL)
    if (elem->chr != c)
      return (NULL);
  return (elem);
}

void		put_on_screen(t_menu *text, t_text *tmp, int i, int j)
{
  t_color	*img;
  t_color	*pixel;
  int		wid;
  int		hei;
  int		pix;

  img = (t_color *)text->png->pixels;
  pixel = (t_color *)text->scr->pixels;
  wid = (j + (2 * tmp->col) + (32 * tmp->col)) + 1;
  hei = (i + (2 * tmp->row) + (32 * tmp->row)) + 1;
  pix = text->pos.x + j + text->count * 34;
  if (pix < text->scr->clipable.clip_width && pix >= 0)
    if (img[wid + hei * text->png->clipable.clip_width].full != img[0].full)
      {
	pixel[pix + (text->pos.y + i + (int)text->move) *
	      text->scr->clipable.clip_width].argb[0] =
	  img[wid + hei * text->png->clipable.clip_width].argb[0];
	pixel[pix + (text->pos.y + i + (int)text->move) *
	      text->scr->clipable.clip_width].argb[1] =
	  img[wid + hei * text->png->clipable.clip_width].argb[1];
	pixel[pix + (text->pos.y + i + (int)text->move) *
	      text->scr->clipable.clip_width].argb[2] =
	  img[wid + hei * text->png->clipable.clip_width].argb[2];
      }
}

void		disalpha(char *str)
{
  int	i;

  i = -1;
  while (str && str[++i])
    if (str[i] >= 'A' && str[i] <= 'Z')
      str[i] = str[i] + 32;
}

void		put_space()
{
  int		i;
  int		j;

  i = -1;
  while (++i < 32)
    {
      j = -1;
      while (++j < 32);
    }
}

void		disp_text(t_text *txt, t_menu *text, char *str)
{
  t_text	*tmp;
  int		i;
  int		j;

  text->count = -1;
  disalpha(str);
  while (str[++text->count])
    {
      if (!(tmp = chk_chr(txt, str[text->count])))
	put_space();
      else
	{
	  i = -1;
	  while (++i < 32)
	    {
	      j = -1;
	      text->move =
		(sin((text->pos.x + text->count) / 5.95 +
		     ((60 * M_PI) / (240))) * (240 / M_PI)) / 2;
	      while (++j < 32)
		put_on_screen(text, tmp, i, j);
	    }
	}
    }
}
