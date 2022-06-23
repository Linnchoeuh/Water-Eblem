/**
 ** @file delete_tile_array.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "tile.h"

void delete_tile_array(t_tile_array *tile_array)
{
	size_t i;

	if (tile_array == NULL)
		return;
	i = 0;
	while (tile_array->tiles != NULL &&
		tile_array->tiles[i] != NULL)
	{
		delete_tile(tile_array->tiles[i]);
		i++;
	}
	if (tile_array->tiles != NULL)
		bunny_free(tile_array->tiles);
	bunny_free(tile_array);
}