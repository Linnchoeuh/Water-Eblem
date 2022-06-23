/**
 ** @file mouse_check_button_pressed.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "mouse.h"

void mouse_check_button_pressed(t_mouse *mouse)
{
	size_t i;

	i = 0;
	while (i < LAST_BUNNY_MOUSEBUTTON)
	{
		mouse->button_pressed[i] =
			(mouse->button[i] && !mouse->__button[i]);
		mouse->__button[i] = mouse->button[i];
		i++;
	}
}