/**
 ** @file game_struct_delete.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "game.h"

static void delete_audio(t_audio *audio)
{
	size_t i;

	i = 0;
	while (i < audio->nbr_sfx)
	{
		if (audio->sfx[i] != NULL)
			bunny_delete_sound(audio->sfx[i]);
		i++;
	}
	i = 0;
	while (i < audio->nbr_music)
	{
		if (audio->music[i] != NULL)
			bunny_delete_sound(audio->music[i]);
		i++;
	}
}

void game_struct_delete(t_game *game)
{
	size_t i;

	if (game == NULL)
		return;
	if (game->ws != NULL)
		bunny_stop(game->ws);
	if (game->pic != NULL)
		bunny_delete_clipable(game->pic);
	i = 0;
	while (i < FS_TOTAL)
	{
		if (game->font[i] != NULL)
			bunny_delete_clipable(game->font[i]);
		i++;
	}
	delete_audio(&game->audio);
	if (game->map != NULL)
		delete_map(game->map);
	free(game);
}