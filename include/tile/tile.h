/**
 ** @file tile.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __TILE_H__
#define __TILE_H__

#include <lapin.h>

#include "tile_struct.h"
#include "key_input_struct.h"
#include "bunny_macro.h"
#include "animation.h"
#include "fe_menu_struct.h"
#include "ui.h"
#include "entities.h"

t_tile *new_tile(void);

t_tile *find_tile(t_tile_array *array,
				  t_bunny_position pos);

void play_tile(t_tile *tile,
			   t_bunny_time time);

void display_tile(t_bunny_buffer *buf,
				  t_tile *tile,
				  t_bunny_area area);

size_t count_tile_layers(t_tile *tile);

bool tile_add_layer(t_tile *tile,
					t_sprite *layer);

bool remove_tile_layer(t_tile *tile,
					   size_t pos);

void clear_tile_layers(t_tile *tile);

void delete_tile(t_tile *tile);



t_tile_array *new_tile_array(t_bunny_position tile_array_size);

void play_tile_array(t_tile_array *tile_array,
					 t_bunny_time time);

void display_tile_array(t_bunny_buffer *buf,
						t_tile_camera cam,
						t_tile_array *tile_array,
						t_editor_data *edit_data);

void delete_tile_array(t_tile_array *tile_array);



void init_tile_camera(t_tile_camera *cam);

void move_tile_camera(t_tile_camera *cam,
					  t_key_input *key_input,
					  double delta_time);

#endif