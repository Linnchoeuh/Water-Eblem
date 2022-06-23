/**
 ** @file change_animation_sprite_sheet.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "animation.h"

void change_animation_sprite(t_animation *anim,
							 t_sprite *sprite)
{
	reset_animation_data(anim);
	anim->sprite = sprite;
}