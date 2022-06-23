/**
 ** @file new_tile_array.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "tile.h"

t_tile_array *new_tile_array(t_bunny_position tile_array_size)
{
	size_t i;
	size_t nbr_of_tile;
	t_tile_array *array;

	array = bunny_malloc(sizeof(t_tile_array));
	if (array == NULL)
		return (NULL);
	array->size = tile_array_size;
	array->tile_size = SETPOS(16,16);
	nbr_of_tile = array->size.x * array->size.y;
	array->tiles = bunny_malloc((nbr_of_tile + 1) * sizeof(t_tile));
	if (array->tiles == NULL)
	{
		delete_tile_array(array);
		return (NULL);
	}
	i = 0;
	while (i < nbr_of_tile)
	{
		array->tiles[i] = new_tile();
		if (array->tiles[i] == NULL)
		{
			delete_tile_array(array);
			return (NULL);
		}
		i++;
	}
	array->tiles[i] = NULL;
	return (array);
}