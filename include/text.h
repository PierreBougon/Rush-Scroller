/*
** text.h for text in /home/duhieu_b/infographie/gfx_scroller/include
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Mar 20 10:42:31 2016 benjamin duhieu
** Last update Sun Mar 20 14:21:12 2016 benjamin duhieu
*/

#ifndef TEXT_H_
# define TEXT_H_
# define PRESENTATION "Welcome, You are the new man who gonna \
play the demon :The Mega-Man, In this game you'll can kill as many rabbit\
as you want, with chicken's scream with your lightsaber !So enjoy, \
Now the Command :     Next-music : M, \
Remix : O, Move right: ->, Move Left: <-\
 Attack: Space, QUIt : ESC ! So bye, and be the power with you"

typedef struct		s_text
{
  char			chr;
  int			col;
  int			row;
  struct s_text		*next;
}			t_text;

#endif /* !TEXT_H_ */
