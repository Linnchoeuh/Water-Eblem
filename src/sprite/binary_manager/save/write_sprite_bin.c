/**
 ** @file write_sprite_bin.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "sprite.h"

bool write_sprite_bin(int fd,
					  t_sprite *sprite)
{
	printo("\rSPRITE SAVER: Writing header...");
	if (!write_sprite_bin_header(fd, sprite))
		return (false);
	printo("\rSPRITE SAVER: Writing sprite sheet...");
	if (!write_sprite_bin_image(fd, sprite))
		return (false);
	printo("SPRITE SAVER: Done.                        \n");
	return (true);
}