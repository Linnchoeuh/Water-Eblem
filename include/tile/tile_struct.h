/**
 ** @file tile_struct.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __TILE_STRUCT_H__
#define __TILE_STRUCT_H__

#include <lapin.h>

#include "animation_struct.h"

typedef struct	s_tile_camera
{
	double zoom;
	t_bunny_accurate_position tile_pos;
	double zoom_limits[2];
}				t_tile_camera;

typedef struct	s_tile
{
	bool is_block;
	t_animation **layers;
}				t_tile;

typedef struct	s_tile_array
{
	t_tile **tiles;
	t_bunny_position size;
	t_bunny_position tile_size;
}				t_tile_array;

#endif

