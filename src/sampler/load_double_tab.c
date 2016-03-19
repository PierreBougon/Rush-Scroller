/*
** load_double_tab.c for mega in ~/RENDU/INFOGRAPHIE/gfx_scroller
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sat Mar 19 20:18:30 2016 marc brout
** Last update Sat Mar 19 22:38:49 2016 marc brout
*/

#include <stdlib.h>
#include "sampler.h"

int		load_double_frequency(t_sample *samp)
{
  const char		*tmp;

  if (!(samp->pitch = bunny_malloc(sizeof(double))))
    return (1);
  samp->lenpit = 0;
  while ((tmp = bunny_ini_scope_get_field(samp->scope, "frequency",
					  samp->lenpit)))
    {
      if (!(samp->pitch = bunny_realloc(samp->pitch, sizeof(double) *
					(samp->lenpit + 1))))
	return (1);
      samp->pitch[samp->lenpit] = atof(tmp);
      samp->lenpit += 1;
    }
  return (0);
}

int		load_double_duration(t_sample *samp)
{
  const char		*tmp;

  if (!(samp->duration = bunny_malloc(sizeof(double))))
    return (1);
  samp->lendur = 0;
  while ((tmp = bunny_ini_scope_get_field(samp->scope, "duration",
					  samp->lendur)))
    {
      if (!(samp->duration = bunny_realloc
	    (samp->duration, sizeof(double) * (samp->lendur + 1))))
	return (1);
      samp->duration[samp->lendur] = atof(tmp);
      samp->lendur += 1;
    }
  return (0);
}
