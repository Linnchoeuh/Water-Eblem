/**
 ** @file play_entity_animation.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "entities.h"

void play_entity_animation(t_entity *entity,
						   t_bunny_time time)
{
	if (entity == NULL)
		return;
	play_animation(entity->animation, time);
}