/**
 ** @file play_tile.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "tile.h"

void play_tile(t_tile *tile,
			   t_bunny_time time)
{
	size_t i;

	i = 0;
	while (tile->layers != NULL &&
		tile->layers[i] != NULL)
	{
		play_animation(tile->layers[i], time);
		i++;
	}
}