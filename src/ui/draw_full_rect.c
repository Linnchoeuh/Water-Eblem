/**
 ** @file draw_full_rect.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "ui.h"

void draw_full_rect(t_bunny_buffer *buf,
					t_bunny_area area,
					unsigned int color)
{
	int x2;
	int y2;
	t_bunny_position pos[2];
	unsigned int colors[2];

	x2 = area.x + area.w;
	colors[0] = color;
	colors[1] = color;
	pos[0].x = area.x;
	pos[1].x = x2;
	y2 = area.y;
	while (y2 < area.y + area.h)
	{
		pos[0].y = y2;
		pos[1].y = y2;
		bunny_set_line(buf, pos, colors);
		y2++;
	}
}