/**
 ** @file map.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __MAP_H__
#define __MAP_H__

#include "map_struct.h"
#include "file_manager.h"
#include "tile.h"
#include "sprite.h"
#include "path.h"
#include "entities.h"
#include "game_struct.h"

#define MAP_HEADER_NAME "F_E_DATA" // (FIRE_EMBLEM_DATA)
#define MAP_HEADER_SIZE 8

/**
 ** @brief /!\\ THIS FUNCTION IS UNCOMPLETE (But it work) /!\\
 ** Create a blank map with the given size.
 **
 ** @param map_size A (t_bunny_position) with the width and the height
 ** of the new map
 ** @return t_map*
 **/
t_map *new_map(t_bunny_position map_size);

void play_map_animation(t_map *map);

void display_map(t_bunny_buffer *buf,
				 t_map *map,
				 t_editor_data *menu_data,
				 t_play_data *play_data);

void delete_map(t_map *map);

void sync_map_collisions(t_map *map,
						 bool src_map_id);



bool save_map(t_map *map,
			  const char *save_path,
			  const char *file_name);

bool write_map_bin(int fd,
				   t_map *map);

bool write_map_bin_header(int fd,
						  t_map *map);

bool write_map_bin_tile_data(int fd,
							 t_map *map);

bool write_map_bin_entity(int fd,
						  t_map *map);



t_map *load_map(const char *save_path,
				const char *file_name);

t_map *read_map_bin(int fd);

bool read_map_bin_header(int fd,
						 t_bunny_position *map_size);

bool read_map_bin_tile_data(int fd,
							t_map *map);

bool read_map_bin_entity(int fd,
						 t_map *map);



size_t len_map_list(t_map_list *map_list);

void add_map_elem(t_map_list *map_list,
				  t_map_elem *new_elem);

t_map_elem *new_map_elem(char *name,
						 char *full_path,
						 t_bunny_position map_size);

void delete_map_elem(t_map_elem *elem);

void delete_map_list(t_map_list *map_list);

t_map_list *create_map_list(char *path);

bool display_map_list(t_bunny_buffer *buf,
					  t_map_list *map_list,
					  t_game *game,
					  int init_y_pos);

#endif