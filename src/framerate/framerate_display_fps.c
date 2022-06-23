/**
 ** @file framerate_display_fps.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "framerate.h"

void framerate_display_fps(t_bunny_buffer *buf,
						   t_bunny_font *font,
						   t_framerate framerate)
{
	char *tmp_str;
	unsigned int tmp_color;
	unsigned int tmp_outline_color;
	double tmp_outline_size;

	tmp_str = generate_str("%f FPS", framerate.current);
	tmp_color = font->color;
	tmp_outline_color = font->outline;
	tmp_outline_size = font->outline_size;
	font->outline = COLOR(255, 0, 0, 0);
	font->outline_size = 2;
	font->color = COLOR(255, 255, 0, 0);
	draw_str(buf, font, tmp_str, SETPOS(0, 0));
	font->color = tmp_color;
	font->outline = tmp_outline_color;
	font->outline_size = tmp_outline_size;
	bunny_free(tmp_str);
}