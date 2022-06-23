/**
 ** @file load_sprite.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

/*
	BINARY FILE INFO :
	(char[8]) 8 bytes header that contains SPRITE_D (SPRITE_DATA)
	(size_t) 8 bytes nbr_of_frame
	(double*) [8 * nbr_of_frame] bytes of delay
	(int) 4 bytes for frame_size x value
	(int) 4 bytes for frame_size y value
	(ssize_t) 8 bytes for image size x value
	(ssize_t) 8 bytes for image size y value
	(uint32_t*) [4 * image_width * image_height] bytes of image data
*/

#include "sprite.h"

int check_file(char *file_name)
{
	int fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		fprinto(STDERR_FILENO,
			"SPRITE LOADER: Couldn't open file: %s\n", file_name);
	return (fd);
}

t_sprite *load_sprite(char *file_name)
{
	int fd;
	t_sprite *sprite;

	fd = check_file(file_name);
	if (fd == -1)
		return (NULL);
	sprite = read_sprite_bin(fd);
	close (fd);
	if (sprite == NULL)
		fprinto(STDERR_FILENO,
			"Failed to read sprite file called : %s\n", file_name);
	return (sprite);
}