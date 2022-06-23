/**
 ** @file range_struct.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __RANGE_STRUCT_H__
#define __RANGE_STRUCT_H__

#include <lapin.h>

#include "tile_struct.h"
#include "entities_struct.h"

typedef struct	s_range
{
	t_bunny_position *pos;
	unsigned int nbr_pos;
	t_tile_array *tile_array;
	t_entity_array *entity_array;
	int up;
	int down;
	int left;
	int right;
}				t_range;

#endif