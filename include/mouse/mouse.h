/**
 ** @file mouse.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __MOUSE_H__
#define __MOUSE_H__

#include <lapin.h>
#include <printo.h>

#include "mouse_struct.h"
#include "bunny_macro.h"

void mouse_init_struct(t_mouse *mouse);

void mouse_check_button_pressed(t_mouse *mouse);

bool mouse_button(t_bunny_area area,
				  t_mouse mouse,
				  int expected_trigger_button,
				  bool *is_area_touched);

#endif