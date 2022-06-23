/**
 ** @file framerate.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __FRAMERATE_H__
#define __FRAMERATE_H__

#include <lapin.h>
#include <stdlib.h>
#include <printo.h>

#include "framerate_struct.h"
#include "bunny_macro.h"
#include "font.h"

void framerate_init_struct(t_framerate *framerate,
						   size_t max_fps);

void update_framerate_data(t_framerate *framerate);

void framerate_log_fps(t_framerate framerate,
					   bool display_type);

void framerate_display_fps(t_bunny_buffer *buf,
						   t_bunny_font *font,
						   t_framerate framerate);

#endif