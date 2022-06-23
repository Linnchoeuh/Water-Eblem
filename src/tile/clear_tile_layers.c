/**
 ** @file clear_tile_layers.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "tile.h"

void clear_tile_layers(t_tile *tile)
{
	size_t i;

	i = 0;
	while (tile->layers != NULL &&
			tile->layers[i] != NULL)
	{
		delete_animation_struct(tile->layers[i]);
		i++;
	}
	if (tile->layers != NULL)
		bunny_free(tile->layers);
	tile->layers = NULL;
}