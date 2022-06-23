/**
 ** @file play_entity_array_animation.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "entities.h"

void play_entity_array_animation(t_entity_array *entity_array,
								 t_bunny_time time)
{
	int i;

	if (entity_array == NULL ||
		entity_array->entities == NULL)
		return;
	i = 0;
	while (i < entity_array->nbr_entities)
	{
		play_entity_animation(&entity_array->entities[i], time);
		i++;
	}
}