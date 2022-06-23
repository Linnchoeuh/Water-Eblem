/**
 ** @file mouse_struct.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __MOUSE_STRUCT_H__
#define __MOUSE_STRUCT_H__

#include <lapin.h>

#include "bunny_macro.h"

#define IS_POINT_IN_AREA(__bunny_area, __bunny_position) ( \
	__bunny_position.x >= __bunny_area.x && \
	__bunny_position.y >= __bunny_area.y && \
	__bunny_position.x < __bunny_area.x + __bunny_area.w && \
	__bunny_position.y < __bunny_area.y + __bunny_area.h \
)

typedef struct	s_mouse
{
	bool button[LAST_BUNNY_MOUSEBUTTON];
	bool button_pressed[LAST_BUNNY_MOUSEBUTTON];
	t_bunny_position pos;
	// t_bunny_wheel
	bool __button[LAST_BUNNY_MOUSEBUTTON];
}		t_mouse;

#endif