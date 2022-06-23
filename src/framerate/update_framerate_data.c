/**
 ** @file update_framerate_data.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "framerate.h"

void update_framerate_data(t_framerate *framerate)
{
	t_bunny_time curr_time;
	t_bunny_time interval_time;

	curr_time = bunny_get_time();
	interval_time = GET_INTERVAL_TIME(curr_time, framerate->prev_time);
	framerate->frame_ms_delay = CONVERT_NS_TO_SECOND(interval_time);
	framerate->delta_time = GET_DELTA_TIME(framerate->frame_ms_delay);
	framerate->current = GET_FPS(framerate->delta_time);
	framerate->prev_time = curr_time;
}