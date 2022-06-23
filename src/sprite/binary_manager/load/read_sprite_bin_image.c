/**
 ** @file read_sprite_bin_image.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "sprite.h"

static t_bunny_pixelarray *get_image_dimension(int fd)
{
	ssize_t	width;
	ssize_t	height;
	ssize_t tmp_size;

	tmp_size = sizeof(ssize_t);
	if (read(fd, &width, tmp_size) != tmp_size)
		return (false);
	if (read(fd, &height, tmp_size) != tmp_size)
		return (NULL);
	return (bunny_new_pixelarray(width, height));
}

bool read_sprite_bin_image(int fd,
						   t_sprite *sprite)
{
	ssize_t buf_size;
	t_bunny_pixelarray *img_tmp;

	if ((img_tmp = get_image_dimension(fd)) == NULL)
		return (false);
	buf_size = img_tmp->clipable.buffer.width *
				  img_tmp->clipable.buffer.height *
				  sizeof(unsigned int);
	if (read(fd, img_tmp->pixels, buf_size) != buf_size)
	{
		bunny_delete_clipable(img_tmp);
		return (false);
	}
	sprite->sheet_img = bunny_new_picture(img_tmp->clipable.buffer.width,
										  img_tmp->clipable.buffer.height);
	if (sprite->sheet_img == NULL)
	{
		bunny_delete_clipable(img_tmp);
		return (false);
	}
	bunny_blit(&sprite->sheet_img->buffer, &img_tmp->clipable, NULL);
	bunny_delete_clipable(img_tmp);
	sprite->sheet_img->origin.x = ((double) sprite->frame_size.x) / 2;
	sprite->sheet_img->origin.y = ((double) sprite->frame_size.y) / 2;
	return (true);
}