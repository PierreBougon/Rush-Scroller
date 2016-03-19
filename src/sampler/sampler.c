/*
** sampler.c for scroller in ~/RENDU/INFOGRAPHIE/gfx_scroller/sampler
**
** Made by marc brout
** Login   <marc brout@epitech.net>
**
** Started on  Fri Mar 18 22:44:57 2016 marc brout
** Last update Sat Mar 19 20:05:45 2016 bougon_p
*/

#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sampler.h"

void		change_music(t_sample **samples,
			     int *curmusic,
			     int *change,
			     int i)
{
  bunny_sound_stop(&samples[*curmusic]->music->sound);
  *curmusic = (*curmusic + i >= 0) ? (*curmusic + i) % NB_SAMPLES :
    NB_SAMPLES - 1 ;
  *change = 1;
}

void		sampler(t_sample *sample, int *change)
{
  static double	ang = 0;
  static int	j = 0;
  static double	i = -1;

  ang = (sample->sinus) ? (ang + 0.5) : 90;
  if (ang > 170)
    ang = 10;
  if (*change && !(j = 0) && (i = -1))
    *change = 0;
  if (((i / 60) ) >= sample->duration[j] / 1000)
    {
      j = ((j + 1) % sample->lendur) % sample->lenpit;
      i = 0;
      if (i != -1)
	bunny_sound_stop(&sample->music->sound);
      bunny_sound_pitch(&sample->music->sound,
			sample->pitch[j] / (441 * sin(RAD(ang))));
      bunny_sound_play(&sample->music->sound);
    }
  i = (int)(i + 1) % 150000;
}

int		load_double_frequency(t_sample *samp)
{
  const char		*tmp;

  if (!(samp->pitch = bunny_malloc(sizeof(double))))
    return (1);
  samp->lenpit = 0;
  while ((tmp = bunny_ini_scope_get_field(samp->scope, "frequency",
					  samp->lenpit)))
    {
      if (!(samp->pitch = realloc(samp->pitch, sizeof(double) *
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
      if (!(samp->duration = realloc(samp->duration, sizeof(double) *
				     (samp->lendur + 1))))
	return (1);
      samp->duration[samp->lendur] = atof(tmp);
      samp->lendur += 1;
    }
  return (0);
}

t_sample	*load_bsf(const char *file, const char *path)
{
  t_sample	*samp;
  int		len;
  char		*musicpath;
  char		*filename;

  if (!file || !path ||
      !(samp = bunny_malloc(sizeof(t_sample))) ||
      !(samp->ini = bunny_load_ini(file)) ||
      !(samp->scope = bunny_ini_first(samp->ini)) ||
      !(samp->scope = bunny_ini_next(samp->ini, samp->scope)) ||
      !(filename = (char *)
	bunny_ini_scope_get_field(samp->scope, "sample", 0)))
    return (NULL);
  len = strlen(filename) + strlen(path) + 1;
  if (!(musicpath = bunny_malloc(len + 1)) ||
      snprintf(musicpath, len + 1, "%s%c%s", path, '/', filename) < 0)
    return (NULL);
  printf("%s \n", musicpath);
  if (!(samp->music = bunny_load_effect(musicpath)) ||
      load_double_duration(samp) || load_double_frequency(samp))
    return (NULL);
  samp->sinus = 0;
  return (samp);
}
