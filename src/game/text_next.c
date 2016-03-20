/*
** text_next.c for text_next
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Mar 20 22:48:04 2016 benjamin duhieu
** Last update Sun Mar 20 22:54:21 2016 benjamin duhieu
*/

#include "mega.h"

void	disp_end(t_data *data)
{
  plasma(data);
}

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

  if (!(text = malloc(sizeof(t_text))))
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
      if (!(elem->next = malloc(sizeof(t_text))))
	return (NULL);
      elem = elem->next;
    }
  elem->next = NULL;
  return (text);
}
