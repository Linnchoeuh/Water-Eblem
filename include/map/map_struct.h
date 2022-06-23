/**
 ** @file map_struct.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __MAP_STRUCT_H__
#define __MAP_STRUCT_H__

#include "sprite_struct.h"
#include "tile_struct.h"
#include "entities_struct.h"

typedef struct s_map_elem
{
	char *name;
	char *full_path;
	t_bunny_position map_size;
}				t_map_elem;

typedef struct s_map_list
{
	bool disable_buttons;
	char *taken_name;
	t_map_elem **elem;
}				t_map_list;

typedef struct s_map
{
	t_tile_camera camera;
	double minimal_zoom;
	t_sprite_bank *map_asset;
	t_sprite_bank *entities_asset;
	t_tile_array *sub_part;
	t_entity_array entity_array;
	t_tile_array *over_part;
}				t_map;

#endif