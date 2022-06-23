/**
 ** @file display_map.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "map.h"

void display_map_on_play_mode(t_bunny_buffer *buf,
							  t_map *map,
							  t_play_data *play_data)
{
	display_tile_array(buf, map->camera, map->sub_part, NULL);
	display_entity_array(buf, &map->entity_array, map->camera, play_data);
	display_tile_array(buf, map->camera, map->over_part, NULL);
}

void display_map_on_edit_mode(t_bunny_buffer *buf,
							  t_map *map,
							  t_editor_data *menu_data)
{
	if (!menu_data->hide_opposite_map ||
		(!menu_data->map_layer && menu_data->hide_opposite_map))
		display_tile_array(buf, map->camera, map->sub_part,
			((!menu_data->any_menu_showed && !menu_data->map_layer) ?
				menu_data : NULL));
	display_entity_array(buf, &map->entity_array, map->camera, NULL);
	if (!menu_data->hide_opposite_map ||
		(menu_data->map_layer && menu_data->hide_opposite_map))
		display_tile_array(buf, map->camera, map->over_part,
			((!menu_data->any_menu_showed && menu_data->map_layer) ?
				menu_data : NULL));
	// printo("%B %B %B\n", !menu_data->hide_opposite_map, (menu_data->map_layer && menu_data->hide_opposite_map), menu_data->map_layer);
}

void display_map(t_bunny_buffer *buf,
				 t_map *map,
				 t_editor_data *menu_data,
				 t_play_data *play_data)
{
	if (menu_data == NULL)
		display_map_on_play_mode(buf, map, play_data);
	else
		display_map_on_edit_mode(buf, map, menu_data);
}