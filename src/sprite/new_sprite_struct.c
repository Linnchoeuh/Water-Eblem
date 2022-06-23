/**
 ** @file new_sprite_struct.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "sprite.h"

t_sprite *new_sprite_struct(void)
{
	t_sprite *sprite;

	sprite = bunny_malloc(sizeof(t_sprite));
	if (sprite == NULL)
		return (NULL);
	sprite->nbr_of_frame = 0;
	sprite->duration = 0;
	sprite->frame_size = SETPOS(0, 0);
	sprite->frame_delay = NULL;
	sprite->sheet_img = NULL;
	return (sprite);
}