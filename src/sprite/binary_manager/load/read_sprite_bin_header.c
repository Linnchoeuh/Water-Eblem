/**
 ** @file read_sprite_bin_header.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "sprite.h"

bool read_sprite_bin_header(int fd,
							t_sprite *sprite)
{
	char header_name[SPRITE_HEADER_SIZE];
	size_t i;
	ssize_t tmp_size;

	if (read(fd, header_name, SPRITE_HEADER_SIZE) != SPRITE_HEADER_SIZE)
		return (false);
	if (term_strncmp(header_name, SPRITE_HEADER_NAME, SPRITE_HEADER_SIZE) != 0)
		return (false);

	tmp_size = sizeof(uint64_t);
	if (read(fd, &sprite->nbr_of_frame, tmp_size) != tmp_size)
		return (false);

	tmp_size = sprite->nbr_of_frame * sizeof(double);
	sprite->frame_delay = bunny_malloc(tmp_size);
	if (sprite->frame_delay == NULL)
		return (false);
	if (read(fd, sprite->frame_delay, tmp_size) != tmp_size)
		return (false);

	tmp_size = 2 * sizeof(int32_t);
	if (read(fd, &sprite->frame_size, tmp_size) != tmp_size)
		return (false);

	i = 0;
	sprite->duration = 0;
	while (i < sprite->nbr_of_frame)
	{
		sprite->duration += sprite->frame_delay[i];
		i++;
	}
	return (true);
}