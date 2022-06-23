/**
 ** @file display_tile_array.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "tile.h"

typedef struct s_tile_array_displayer_cache
{
	unsigned int pos_1d;
	t_bunny_area on_screen_pos;
	t_tile_camera cam;
	t_bunny_position pos;
	t_bunny_accurate_position tile_size;
}				t_tile_array_displayer_cache;

void show_editor_features(t_bunny_buffer *buf,
						  t_tile_array_displayer_cache *cache,
						  t_tile_array *tile_array,
						  t_editor_data *edit_data)
{
	bool touched;
	t_tile *tile;
	t_bunny_area area;
	t_bunny_area low_area;
	unsigned int collide_color;

	tile = tile_array->tiles[cache->pos_1d];
	area = SETAREA(cache->on_screen_pos.x, cache->on_screen_pos.y,
					cache->tile_size.x, cache->tile_size.y);
	low_area = SETAREA(area.x + 1, area.y + 1, area.w - 2, area.h - 2);
	collide_color = (tile->is_block ? RED : BLUE);
	if (edit_data->show_collision)
	{
		draw_rect(buf, area, collide_color);
		draw_rect(buf, low_area, collide_color);
	}
	if (mouse_button(area, *(edit_data->mouse), BMB_LEFT, &touched))
	{
		if (!edit_data->block_placing &&
			tile_add_layer(tile, edit_data->selected_sprite->sprite))
		{
			tile->layers[count_tile_layers(tile) - 1]->rotation =
				edit_data->selected_sprite->rotation;
			tile->layers[count_tile_layers(tile) - 1]->mirror =
				edit_data->selected_sprite->mirror;
		}
		else
		{
			edit_data->entity.animation->mirror = false;
			edit_data->entity.animation->rotation = ROT_0;
			edit_data->entity.pos = cache->pos;
			edit_data->add_entity_request = true;
		}
	}

	if (touched)
	{
		draw_rect(buf, area, YELLOW);
		draw_rect(buf, low_area, YELLOW);
	}
	if (mouse_button(area, *(edit_data->mouse), BMB_MIDDLE, &touched))
		tile->is_block = !tile->is_block;
	if (mouse_button(area, *(edit_data->mouse), BMB_RIGHT, &touched))
	{
		edit_data->zoom = cache->cam.zoom;
		edit_data->zoom_max = cache->cam.zoom_limits[1];
		edit_data->pos_1d = cache->pos_1d;
		edit_data->tile_pos = cache->pos;
		edit_data->side_window = true;
	}
}

t_bunny_area get_start_tile(t_bunny_position screen,
							t_bunny_accurate_position cam_pos,
							t_bunny_accurate_position tile_size,
							t_bunny_position tile_array_size)
{
	t_bunny_area start_tile;
	t_bunny_accurate_position nbr_tile_displayed;

	nbr_tile_displayed.x = ((double) screen.x) / tile_size.x;
	nbr_tile_displayed.y = ((double) screen.y) / tile_size.y;
	cam_pos.x += 0.5;
	cam_pos.y += 0.5;
	start_tile.x = cam_pos.x - (nbr_tile_displayed.x / 2);
	if (start_tile.x < 0)
		start_tile.x = 0;
	start_tile.y = cam_pos.y - (nbr_tile_displayed.y / 2);
	if (start_tile.y < 0)
		start_tile.y = 0;
	start_tile.w = cam_pos.x + (nbr_tile_displayed.x / 2) + 1;
	if (start_tile.w > tile_array_size.x)
		start_tile.w = tile_array_size.x;
	start_tile.h = cam_pos.y + (nbr_tile_displayed.y / 2) + 1;
	if (start_tile.h > tile_array_size.y)
		start_tile.h = tile_array_size.y;
	return (start_tile);
}

void display_tile_array(t_bunny_buffer *buf,
						t_tile_camera cam,
						t_tile_array *tile_array,
						t_editor_data *edit_data)
{
	t_bunny_area tile_bound;
	t_bunny_position screen;
	t_bunny_position offset;
	t_tile_array_displayer_cache cache;

	cache.cam = cam;
	screen = SETPOS(buf->width, buf->height);
	cache.tile_size.x = tile_array->tile_size.x * cam.zoom;
	cache.tile_size.y = tile_array->tile_size.y * cam.zoom;
	offset.x = screen.x / 2 - cache.tile_size.x / 2;
	offset.y = screen.y / 2 - cache.tile_size.y / 2;
	tile_bound = get_start_tile(screen, cam.tile_pos,
		cache.tile_size, tile_array->size);
	cache.pos.y = tile_bound.y;
	while (cache.pos.y < tile_bound.h)
	{
		cache.pos.x = tile_bound.x;
		while (cache.pos.x < tile_bound.w)
		{
			cache.pos_1d =
				BI_TO_ONE_DIMENSION(cache.pos.x, cache.pos.y, tile_array->size.x);
			cache.on_screen_pos.x = (cache.pos.x - cam.tile_pos.x) *
				cache.tile_size.x + offset.x;
			cache.on_screen_pos.y = (cache.pos.y - cam.tile_pos.y) *
				cache.tile_size.y + offset.y;
			cache.on_screen_pos.w = cache.tile_size.x;
			cache.on_screen_pos.h = cache.tile_size.y;
			display_tile(buf, tile_array->tiles[cache.pos_1d], cache.on_screen_pos);
			if (edit_data != NULL)
				show_editor_features(buf, &cache, tile_array, edit_data);
			cache.pos.x++;
		}
		cache.pos.y++;
	}
}