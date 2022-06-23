/**
 ** @file ui.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __UI_H__
#define __UI_H__

#include <lapin.h>

#include "ui_struct.h"
#include "mouse.h"
#include "font.h"
#include "libstd.h"

void draw_rect(t_bunny_buffer *buf,
			   t_bunny_area area,
			   unsigned int color);

void draw_full_rect(t_bunny_buffer *buf,
					t_bunny_area area,
					unsigned int color);

t_button_data new_button(t_bunny_position pos,
						 t_bunny_font *font,
						 unsigned int touched_color,
						 t_bunny_position *rect_size);

bool draw_button(t_bunny_buffer *buf,
				 t_button_data *button_data,
				 t_mouse mouse,
				 char *text);


void set_button_color_set(t_button_data *button_data,
						  unsigned int touched_color);

#endif