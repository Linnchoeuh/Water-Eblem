/**
 ** @file reset_animation_data.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "animation.h"

void reset_animation_data(t_animation *anim)
{
	anim->time_elapsed = 0;
	anim->curr_frame = 0;
	anim->rotation = ROT_0;
	anim->mirror = false;
	anim->is_playing = false;
}