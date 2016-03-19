/*
** init_sampler.c for mega
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sat Mar 19 18:09:47 2016 marc brout
** Last update Sat Mar 19 19:16:57 2016 marc brout
*/

#include "sampler.h"
#include "mega.h"

int	init_sampler(t_data *data)
{
  if (!(data->samples[0] = load_bsf(BSF_1, SAMPLE_FOLD)))
    return (1);
  data->curmusic = 0;
  data->change = 0;
  return (0);
}

void	sampler_keys(t_data *data, t_bunny_keysym keysym)
{
  if (keysym == BKS_P)
    change_music(data->samples, &data->curmusic,
		 &data->change, 1);
  if (keysym == BKS_M)
    change_music(data->samples, &data->curmusic,
		 &data->change, -1);
  if (keysym == BKS_O)
    data->samples[data->curmusic]->sinus =
      (data->samples[data->curmusic]->sinus) ? 0 : 1;
}
