/**
 ** @file framerate_init_struct.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "framerate.h"

void framerate_init_struct(t_framerate *framerate,
						   size_t max_fps)
{
	framerate->prev_time = 0;
	framerate->current = 0;
	framerate->delta_time = 0;
	framerate->frame_ms_delay = 0;
	framerate->max = max_fps;
}