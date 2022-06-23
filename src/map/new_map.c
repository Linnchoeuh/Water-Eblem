/**
 ** @file new_map.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "map.h"

t_map *new_map(t_bunny_position map_size)
{
	t_map *map;

	map = bunny_malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->map_asset = NULL;
	map->entities_asset = load_sprite_from_dir(ENTITIES_ASSET_PATH);
	map->sub_part = new_tile_array(map_size);
	map->over_part = new_tile_array(map_size);
	map->entity_array = new_entity_array();
	if (map->sub_part == NULL ||
		map->over_part == NULL)
	{
		delete_map(map);
		return (NULL);
	}
	init_tile_camera(&map->camera);
	map->camera.tile_pos = SETPOS_ACC(map_size.x / 2,
									  map_size.y / 2);
	return (map);
}