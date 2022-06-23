/**
 ** @file framerate_log_fps.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "framerate.h"

void framerate_log_fps(t_framerate framerate,
					   bool display_type)
{
	if (display_type)
		printo("FPS : %f | DT : %f\n",
			framerate.current, framerate.delta_time);
	else
		printo("\rFPS : %f | DT : %f          ",
			framerate.current, framerate.delta_time);
}