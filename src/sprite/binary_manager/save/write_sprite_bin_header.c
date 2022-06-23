/**
 ** @file write_sprite_bin_header.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "sprite.h"

bool write_sprite_bin_header(int fd,
							 t_sprite *sprite)
{
	ssize_t tmp_size;

	if (write(fd, SPRITE_HEADER_NAME, SPRITE_HEADER_SIZE) != SPRITE_HEADER_SIZE)
		return (false);
	tmp_size = sizeof(uint64_t);
	if (write(fd, &sprite->nbr_of_frame, tmp_size) != tmp_size)
		return (false);
	tmp_size = sprite->nbr_of_frame * sizeof(double);
	if (write(fd, sprite->frame_delay, tmp_size) != tmp_size)
			return (false);

	tmp_size = 2 * sizeof(int32_t);
	if (write(fd, &sprite->frame_size, tmp_size) != tmp_size)
		return (false);
	return (true);
}