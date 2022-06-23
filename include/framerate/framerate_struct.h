/**
 ** @file framerate_struct.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __FRAMERATE_STRUCT_H__
#define __FRAMERATE_STRUCT_H__

#include <lapin.h>

#define BASE_UPDATE_PER_SECOND 60
#define SECOND_IN_NANO_SECONDS 1e9

#define BASE_FRAME_DELTA_TIME \
	(((double) 1) / ((double) BASE_UPDATE_PER_SECOND))

#define GET_INTERVAL_TIME(__curr_time, __prev_time) \
	((__curr_time) - (__prev_time))

#define CONVERT_NS_TO_SECOND(__interval_time) \
	(((double) (__interval_time)) / ((double) SECOND_IN_NANO_SECONDS))

#define GET_DELTA_TIME(__frame_ms_delay) \
	(((double) (__frame_ms_delay)) / BASE_FRAME_DELTA_TIME)

#define GET_FPS(__delta_time) \
	(BASE_UPDATE_PER_SECOND / ((double) (__delta_time)))

typedef struct	s_framerate
{
	t_bunny_time prev_time;
	double delta_time;
	double current;
	double frame_ms_delay;
	size_t max;
}				t_framerate;

#endif