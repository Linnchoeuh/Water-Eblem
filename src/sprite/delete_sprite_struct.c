/**
 ** @file delete_sprite_struct.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "sprite.h"

void delete_sprite_struct(t_sprite *sprite)
{
	if (sprite == NULL)
		return;
	if (sprite->sheet_img != NULL)
		bunny_delete_clipable(sprite->sheet_img);
	if (sprite->frame_delay != NULL)
		bunny_free(sprite->frame_delay);
	bunny_free(sprite);
}