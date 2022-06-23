/**
 ** @file count_tile_layers.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "tile.h"

size_t count_tile_layers(t_tile *tile)
{
	size_t i;

	if (tile == NULL ||
		tile->layers == NULL)
		return (0);
	i = 0;
	while (tile->layers[i] != NULL)
		i++;
	return (i);
}