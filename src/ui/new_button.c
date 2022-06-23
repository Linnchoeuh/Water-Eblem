/**
 ** @file new_button.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "ui.h"

t_button_data new_button(t_bunny_position pos,
						 t_bunny_font *font,
						 unsigned int touched_color,
						 t_bunny_position *rect_size)
{
	t_button_data button_data;

	set_button_color_set(&button_data, touched_color);
	button_data.pos = pos;
	button_data.font = font;
	button_data.size_rect_to_text = (rect_size == NULL);
	button_data.center_rect = false;
	button_data.center_text = false;
	if (!button_data.size_rect_to_text)
	{
		button_data.rect_size.x = rect_size->x;
		button_data.rect_size.y = rect_size->y;
	}
	button_data.touched_sound = NULL;
	button_data.clicked_sound = NULL;
	button_data.already_touched = false;
	button_data.disable_button = false;
	return (button_data);
}