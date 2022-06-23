/**
 ** @file mouse_button.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "mouse.h"

bool mouse_button(t_bunny_area area,
				  t_mouse mouse,
				  int expected_trigger_button,
				  bool *is_area_touched)
{
	bool tmp_is_area_touched;

	tmp_is_area_touched = IS_POINT_IN_AREA(area, mouse.pos);
	if (is_area_touched != NULL)
		*is_area_touched = tmp_is_area_touched;
	return (tmp_is_area_touched &&
		mouse.button_pressed[expected_trigger_button]);
}