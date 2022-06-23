/**
 ** @file sync_map_collisions.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "map.h"

void sync_map_collisions(t_map *map,
						 bool src_map_id)
{
	size_t i;
	t_tile_array *src_map;
	t_tile_array *dest_map;

	if (src_map_id)
	{
		src_map = map->over_part;
		dest_map = map->sub_part;
	}
	else
	{
		src_map = map->sub_part;
		dest_map = map->over_part;
	}
	i = 0;
	while (map->sub_part->tiles[i] != NULL)
	{
		dest_map->tiles[i]->is_block = src_map->tiles[i]->is_block;
		i++;
	}
}