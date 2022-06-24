/**
 ** @file find_entity.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "entities.h"

t_entity find_entity(t_entity_array *array,
					       t_bunny_position pos,
						   int *entity_pos)
{
	int i;
	t_entity entity;

	i = 0;
	entity = new_entity(NULL, NO_CLASS, SETPOS(-1, -1));
	while (i < array->nbr_entities)
	{
		entity = array->entities[i];
		if (pos.x == entity.pos.x && pos.y == entity.pos.y)
		{
			if (entity_pos != NULL)
				*entity_pos = i;
			return (array->entities[i]);
		}
		i++;
	}
	if (entity_pos != NULL)
		*entity_pos = -1;
	return (entity);
}