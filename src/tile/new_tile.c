/**
 ** @file new_tile.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "tile.h"

t_tile *new_tile(void)
{
	t_tile *tile;

	tile = bunny_malloc(sizeof(t_tile));
	if (tile == NULL)
		return (NULL);
	tile->is_block = false;
	tile->layers = NULL;
	return (tile);
}