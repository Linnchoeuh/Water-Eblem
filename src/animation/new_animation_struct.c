/**
 ** @file new_animation_struct.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "animation.h"

t_animation *new_animation_struct(t_sprite *sprite)
{
	t_animation *animation;

	animation = bunny_malloc(sizeof(t_animation));
	if (animation == NULL)
		return (NULL);
	reset_animation_data(animation);
	animation->sprite = sprite;
	return (animation);
}