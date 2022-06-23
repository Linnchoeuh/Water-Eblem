/**
 ** @file delete_tile.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "tile.h"

void delete_tile(t_tile *tile)
{

	if (tile == NULL)
		return;
	clear_tile_layers(tile);
	bunny_free(tile);
}