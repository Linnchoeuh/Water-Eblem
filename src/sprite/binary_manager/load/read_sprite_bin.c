/**
 ** @file read_sprite_bin.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "sprite.h"

t_sprite *read_sprite_bin(int fd)
{
	t_sprite *sprite;

	sprite = new_sprite_struct();
	if (sprite == NULL)
		return (NULL);
	printo("\rSPRITE LOADER: Reading header...");
	if (!read_sprite_bin_header(fd, sprite))
		return (NULL);
	printo("\rSPRITE LOADER: Reading sprite sheet...");
	if (!read_sprite_bin_image(fd, sprite))
		return (NULL);
	printo("\rSPRITE LOADER: Done.                     \n");
	return (sprite);
}