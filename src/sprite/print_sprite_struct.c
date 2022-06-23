/**
 ** @file print_sprite_struct.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "sprite.h"

void print_sprite_struct(t_sprite *sprite)
{
	size_t i;

	if (sprite == NULL)
		return;
	printo("Number of frame: %d\n",
		sprite->nbr_of_frame);
	printo("Frame size:\n\tx: %d\n\ty: %d\n",
		sprite->frame_size.x, sprite->frame_size.y);
	printo("Frame delay:\n");
	i = 0;
	while (i < sprite->nbr_of_frame)
	{
		printo("\tFrame %d/%d : %f sec\n",
			i, sprite->nbr_of_frame, sprite->frame_delay[i]);
		i++;
	}
}