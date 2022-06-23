/**
 ** @file display_tile.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "tile.h"

void display_tile(t_bunny_buffer *buf,
				  t_tile *tile,
				  t_bunny_area area)
{
	uint16_t i;

	if (tile->layers == NULL)
		return;
	i = 0;
	while (tile->layers[i] != NULL)
	{
		display_animation(buf, tile->layers[i], area);
		i++;
	}
}