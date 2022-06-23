/**
 ** @file play_map_animation.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "map.h"

void play_map_animation(t_map *map)
{
	t_bunny_time time;

	time = bunny_get_time();
	play_tile_array(map->sub_part, time);
	play_entity_array_animation(&map->entity_array, time);
	play_tile_array(map->over_part, time);
}