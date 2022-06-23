/**
 ** @file find_tile.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "tile.h"

t_tile *find_tile(t_tile_array *array,
				  t_bunny_position pos)
{
	int pos_1d;

	if (pos.x < 0 || pos.x >= array->size.x ||
		pos.y < 0 || pos.y >= array->size.y)
		return (NULL);
	pos_1d = BI_TO_ONE_DIMENSION(pos.x, pos.y, array->size.x);
	return (array->tiles[pos_1d]);
}