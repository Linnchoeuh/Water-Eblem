/**
 ** @file play_tile_array.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "tile.h"

void play_tile_array(t_tile_array *tile_array,
					 t_bunny_time time)
{
	size_t i;

	i = 0;
	while (tile_array->tiles != NULL &&
			tile_array->tiles[i] != NULL)
	{
		play_tile(tile_array->tiles[i], time);
		i++;
	}
}