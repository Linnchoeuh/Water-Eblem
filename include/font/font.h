/**
 ** @file font.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/


#ifndef __FONT_H__
#define __FONT_H__

#include <lapin.h>

#include "font_struct.h"
#include "bunny_macro.h"
#include "libstd.h"

int draw_str(t_bunny_buffer *buf,
			 t_bunny_font *font,
			 char *str,
			 t_bunny_position pos);

void draw_str_in_box(t_bunny_buffer *buf,
					 t_bunny_font *font,
					 char *str,
					 t_bunny_area area);

#endif