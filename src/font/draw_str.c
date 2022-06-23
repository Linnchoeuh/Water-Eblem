/**
 ** @file draw_str.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "font.h"

int draw_str(t_bunny_buffer *buf,
			 t_bunny_font *font,
			 char *str,
			 t_bunny_position pos)
{
	font->string = str;
	font->string_len = term_strlen(str);

	bunny_clear(&font->clipable.buffer, COLOR(0, 0, 0, 0));
	bunny_draw(&font->clipable);
	bunny_blit(buf, &font->clipable, &pos);
	font->string = "";
	font->string_len = 0;
	return (font->glyph_size.y * FONT_RATIO * term_strlen(str));
}