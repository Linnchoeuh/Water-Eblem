/**
 ** @file stop_animation.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "animation.h"

void stop_animation(t_animation *animation)
{
	animation->is_playing = false;
	animation->curr_frame = 0;
	animation->time_elapsed = 0;
}