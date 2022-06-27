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

typedef enum e_elem_on_tile
{
	TILE_NOTHING,
	TILE_NONE,
	TILE_ALLY,
	TILE_ENEMY,
	TILE_ATTACK,
	TILE_ALLY_HEAL,
	TILE_HEAL,
	NBR_TILE_TYPE
}				t_elem_on_tile;

typedef struct s_range_data
{
	t_bunny_position pos;
	int type;
}				t_range_data;

typedef struct	s_range
{
	t_range_data *data;
	unsigned int nbr_pos;
	t_entity *entity;
	t_tile_array *tile_array;
	t_entity_array *entity_array;
	int up;
	int down;
	int left;
	int right;
}				t_range;

#endif