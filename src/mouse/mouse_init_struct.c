/**
 ** @file mouse_init_struct.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "mouse.h"

void mouse_init_struct(t_mouse *mouse)
{
	size_t i;

	i = 0;
	while (i < LAST_BUNNY_MOUSEBUTTON)
	{
		mouse->button[i] = false;
		mouse->__button[i] = false;
		mouse->button_pressed[i] = false;
		i++;
	}
	mouse->pos = SETPOS(0, 0);
}