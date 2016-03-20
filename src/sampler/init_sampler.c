/*
** init_sampler.c for mega
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sat Mar 19 18:09:47 2016 marc brout
** Last update Sun Mar 20 09:53:43 2016 marc brout
*/

#include "sampler.h"
#include "mega.h"

int	init_sampler(t_data *data)
{
  if (!(data->samples[0] = load_bsf(BSF_1, SAMPLE_FOLD)) ||
      !(data->samples[1] = load_bsf(BSF_2, SAMPLE_FOLD)))
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

void	free_sampler(t_data *data)
{
  int	i;

  i = 0;
  while (i < NB_SAMPLES)
    {
      bunny_free(data->samples[i]->pitch);
      bunny_free(data->samples[i]->duration);
      bunny_delete_ini(data->samples[i]->ini);
      bunny_delete_sound(&data->samples[i]->music->sound);
      i += 1;
    }
}
