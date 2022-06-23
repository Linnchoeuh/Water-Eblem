/**
 ** @file delete_map.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "map.h"

void delete_map(t_map *map)
{
	if (map == NULL)
		return;
	if (map->map_asset != NULL)
		delete_sprite_bank(map->map_asset);
	if (map->entities_asset != NULL)
		delete_sprite_bank(map->entities_asset);
	if (map->over_part != NULL)
		delete_tile_array(map->over_part);
	if (map->sub_part != NULL)
		delete_tile_array(map->sub_part);
	if (map->entity_array.entities != NULL)
		delete_entity_array(&map->entity_array);
	bunny_free(map);
}