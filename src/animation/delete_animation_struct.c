/**
 ** @file delete_animation_struct.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "animation.h"

void delete_animation_struct(t_animation *animation)
{
	if (animation == NULL)
		return;
	bunny_free(animation);
}