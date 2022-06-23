/**
 ** @file display_animation.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "animation.h"

void display_animation(t_bunny_buffer *buf,
					   t_animation *anim,
					   t_bunny_area area)
{
	t_bunny_picture *pic;
	t_bunny_position tmp_pos;

	if (anim->sprite == NULL)
		return;
	pic = anim->sprite->sheet_img;
	pic->rotation = anim->rotation;
	pic->scale.x = ((double) area.w) /
		((double) anim->sprite->frame_size.x);
	pic->scale.y = ((double) area.h) /
		((double) anim->sprite->frame_size.y);
	pic->scale.x *= (anim->mirror) ? -1 : 1;
	pic->rotation = anim->rotation;
	tmp_pos.x = area.x + area.w / 2;
	tmp_pos.y = area.y + area.h / 2;
	pic->clip_x_position = anim->sprite->frame_size.x * anim->curr_frame;
	pic->clip_width = anim->sprite->frame_size.x;
	bunny_blit(buf, pic, &tmp_pos);
}