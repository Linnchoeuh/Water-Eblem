/**
 ** @file draw_button.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "ui.h"

t_bunny_area set_base_rect_area(t_button_data *button_data,
								char *text)
{
	t_bunny_area rect;

	rect.x = button_data->pos.x;
	rect.y = button_data->pos.y;
	if (button_data->size_rect_to_text)
	{
		rect.w = term_strlen(text) * ((double) button_data->font->glyph_size.y) * FONT_RATIO;
		rect.h = button_data->font->glyph_size.y;
	}
	else
	{
		rect.w = button_data->rect_size.x;
		rect.h = button_data->rect_size.y;
	}
	return (rect);
}

bool draw_button(t_bunny_buffer *buf,
				 t_button_data *button_data,
				 t_mouse mouse,
				 char *text)
{
	bool area_touched;
	bool clicked;
	t_bunny_area rect;
	unsigned int original_color;

	rect = set_base_rect_area(button_data, text);
	if (button_data->center_rect)
	{
		rect.x -= rect.w / 2;
		rect.y -= rect.h / 2;
	}
	original_color = button_data->font->color;
	button_data->font->color = button_data->idle_color;
	clicked = false;
	area_touched = false;
	if (!button_data->disable_button)
	{
		clicked = mouse_button(rect, mouse, BMB_LEFT, &area_touched);
		if (clicked)
		{
			button_data->font->color = button_data->clicked_color;
			if (button_data->clicked_sound != NULL)
			{
				bunny_sound_set_cursor(&button_data->clicked_sound->sound, 0);
				bunny_sound_play(&button_data->clicked_sound->sound);
			}
		}
		else if (area_touched)
			button_data->font->color = button_data->touched_color;

		if (area_touched)
		{
			draw_rect(buf, rect, button_data->font->color);
			if (!button_data->already_touched &&
				button_data->touched_sound != NULL)
				{
					bunny_sound_set_cursor(
						&button_data->touched_sound->sound, 0);
					bunny_sound_play(&button_data->touched_sound->sound);
				}
		}
		button_data->already_touched = area_touched;
	}
	draw_str(buf, button_data->font, text, SETPOS(rect.x, rect.y));
	button_data->font->color = original_color;
	return (clicked);
}