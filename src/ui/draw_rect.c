/**
 ** @file draw_rect.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "ui.h"

void draw_rect(t_bunny_buffer *buf,
			   t_bunny_area area,
			   unsigned int color)
{
	int x2;
	int y2;
	t_bunny_position pos[2];
	unsigned int colors[2];

	x2 = area.x + area.w;
	y2 = area.y + area.h - 1;
	area.x += 1;
	colors[0] = color;
	colors[1] = color;
	pos[0] = SETPOS(area.x, area.y);
	pos[1] = SETPOS(x2, area.y);
	bunny_set_line(buf, pos, colors);
	pos[0] = SETPOS(x2, y2);
	// pos[1] = SETPOS(x2, y2);
	bunny_set_line(buf, pos, colors);
	pos[1] = SETPOS(area.x - 1, y2);
	// pos[1] = SETPOS(x2, area.y);
	bunny_set_line(buf, pos, colors);
	// pos[0] = SETPOS(area.x, area.y);
	pos[0] = SETPOS(area.x, area.y);
	bunny_set_line(buf, pos, colors);
}