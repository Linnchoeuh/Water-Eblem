/**
 ** @file set_button_color_set.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "ui.h"

void set_button_color_set(t_button_data *button_data,
						  unsigned int touched_color)
{
	t_bunny_color bcolor;

	bcolor.full = touched_color;
	bcolor.argb[RED_CMP] *= 0.75;
	bcolor.argb[GREEN_CMP] *= 0.75;
	bcolor.argb[BLUE_CMP] *= 0.75;
	button_data->idle_color = bcolor.full;
	bcolor.full = touched_color;
	bcolor.argb[RED_CMP] = 255 - bcolor.argb[RED_CMP];
	bcolor.argb[GREEN_CMP] = 255 - bcolor.argb[GREEN_CMP];
	bcolor.argb[BLUE_CMP] = 255 - bcolor.argb[BLUE_CMP];
	button_data->clicked_color = bcolor.full;
	button_data->touched_color = touched_color;
}