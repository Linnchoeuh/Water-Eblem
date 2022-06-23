/**
 ** @file animation_struct.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __ANIMATION_STRUCT_H__
#define __ANIMATION_STRUCT_H__

#include <lapin.h>

#include "sprite_struct.h"

#define ROT_0 0
#define ROT_90 90
#define ROT_180 180
#define ROT_270 270

typedef struct	s_mirror
{
	bool x;
	bool y;
}				t_mirror;

typedef struct	s_animation
{
	t_sprite *sprite;
	double time_elapsed;
	t_bunny_time time_in_ns;
	size_t curr_frame;
	double rotation;
	bool mirror;
	bool is_playing;
}				t_animation;

#endif