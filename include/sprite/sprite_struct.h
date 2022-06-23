/**
 ** @file sprite_struct.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __SPRITE_STRUCT_H__
#define __SPRITE_STRUCT_H__

#include <lapin.h>

#define SPRITE_HEADER_SIZE 8
#define SPRITE_HEADER_NAME "SPRITE_D"

typedef struct s_sprite
{
	t_bunny_picture *sheet_img;
	t_bunny_position frame_size;
	size_t nbr_of_frame;
	double *frame_delay;
	double duration;
}				t_sprite;

typedef struct	s_sprite_bank
{
	t_sprite **sprites;
}				t_sprite_bank;

#endif