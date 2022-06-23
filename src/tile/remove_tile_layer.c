/**
 ** @file remove_tile_layer.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "tile.h"

bool remove_tile_layer(t_tile *tile,
					   size_t pos)
{
	size_t size;
	t_animation **layers;

	size = count_tile_layers(tile);
	if (pos >= size)
		return (false);
	layers = bunny_malloc(size * sizeof(t_animation*));
	if (layers == NULL)
		return (false);
	memcpy(layers, tile->layers, pos * sizeof(t_animation*));
	memcpy(&layers[pos], &tile->layers[pos + 1],
		(size - pos - 1) * sizeof(t_animation*));
	layers[size - 1] = NULL;
	delete_animation_struct(tile->layers[pos]);
	bunny_free(tile->layers);
	tile->layers = layers;
	return (true);
}