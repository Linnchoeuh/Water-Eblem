/**
 ** @file range.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __RANGE_H__
#define __RANGE_H__

#include <lapin.h>

#include "range_struct.h"
#include "entities.h"
#include "tile.h"

t_range *find_range(t_tile_array *tile_array,
					t_entity_array *entity_array,
					t_entity *entity,
					int turn);

void display_range(t_bunny_buffer *buf,
				   t_range *range,
				   t_tile_camera cam,
				   t_play_data *m_data);

void delete_range(t_range *range);

#endif