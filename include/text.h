/*
** text.h for text in /home/duhieu_b/infographie/gfx_scroller/include
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Mar 20 10:42:31 2016 benjamin duhieu
** Last update Sun Mar 20 11:32:06 2016 benjamin duhieu
*/

#ifndef TEXT_H_
# define TEXT_H_

typedef struct		s_text
{
  char			chr;
  int			col;
  int			row;
  struct s_text		*next;
}			t_text;

#endif /* !TEXT_H_ */
