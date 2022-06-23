/**
 ** @file write_sprite_bin_image.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "sprite.h"

bool write_sprite_bin_image(int fd,
							t_sprite *sprite)
{
	ssize_t tmp_size;
	t_bunny_buffer *buf;
	t_bunny_picture *pic;
	t_bunny_position tmp_pos;
	t_bunny_pixelarray *px;

	pic = sprite->sheet_img;
	buf = &pic->buffer;
	tmp_size = sizeof(int64_t);
	if (write(fd, &buf->width, tmp_size) != tmp_size)
		return (false);
	if (write(fd, &buf->height, tmp_size) != tmp_size)
		return (false);
	px = bunny_new_pixelarray(buf->width, buf->height);
	if (px == NULL)
		return (false);
	tmp_pos = SETPOS(pic->clip_width, pic->clip_height);
	pic->clip_width = buf->width;
	pic->clip_height = buf->height;
	pic->clip_x_position = 0;
	pic->clip_y_position = 0;
	bunny_blit(&px->clipable.buffer, sprite->sheet_img, NULL);
	pic->clip_width = tmp_pos.x;
	pic->clip_height = tmp_pos.y;
	tmp_size = sizeof(uint32_t) * buf->width * buf->height;
	if (write(fd, px->pixels, tmp_size) != tmp_size)
	{
		bunny_delete_clipable(px);
		return (false);
	}
	bunny_delete_clipable(px);
	return (true);
}