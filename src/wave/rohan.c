/*
** mort.c for mort
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Wed Jan  6 23:41:59 2016 marc brout
** Last update Sun Mar 20 19:58:00 2016 benjamin duhieu
*/

/* #include "rohan.h" */

/* t_bunny_response	main_loop_rohan(void *data) */
/* { */
/*   t_rohan		*rohan; */

/*   rohan = data; */
/*   my_back(rohan->temp); */
/*   copy(rohan); */
/*   rohan->turn += 1; */
/*   bunny_blit(&rohan->win->buffer, &rohan->temp->clipable, NULL); */
/*   bunny_display(rohan->win); */
/*   return (GO_ON); */
/* } */

/* t_bunny_response	my_key_rohan(t_bunny_event_state state, */
/* 				     t_bunny_keysym keysym, */
/* 				     void *data) */
/* { */
/*   if (keysym == BKS_ESCAPE) */
/*     if (state == GO_DOWN) */
/*       { */
/* 	(void)data; */
/* 	return (EXIT_ON_SUCCESS); */
/*       } */
/*   return (GO_ON); */
/* } */

/* void		aff_rohan(t_rohan *rohan, char *img) */
/* { */
/*   t_bunny_key	keyesc; */

/*   keyesc = &my_key_rohan; */
/*   if ((rohan->pix = bunny_load_pixelarray(img)) == NULL || */
/*       (rohan->temp = bunny_new_pixelarray */
/*        (rohan->pix->clipable.clip_width * 3, */
/* 	rohan->pix->clipable.clip_height * 3)) == NULL || */
/*       (rohan->win = bunny_start(rohan->temp->clipable.clip_width, */
/* 				rohan->temp->clipable.clip_height, */
/* 				0, "LA MUERTA")) == NULL) */
/*     return ; */
/*   rohan->decal = 0; */
/*   rohan->turn = 0; */
/*   bunny_set_key_response(keyesc); */
/*   bunny_set_loop_main_function(main_loop_rohan); */
/*   bunny_loop(rohan->win, 30, rohan); */
/*   bunny_delete_clipable(&rohan->pix->clipable); */
/*   bunny_delete_clipable(&rohan->temp->clipable); */
/*   bunny_stop(rohan->win); */
/* } */
