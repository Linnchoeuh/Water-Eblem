/**
 ** @file delete_entities.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "entities.h"

void delete_entity_array(t_entity_array *entity_array)
{
	int i;

	i = 0;
	if (entity_array == NULL ||
		entity_array->entities == NULL)
		return;
	while (i < entity_array->nbr_entities)
	{
		delete_entity(&entity_array->entities[i]);
		i++;
	}
	if (entity_array->entities != NULL)
		bunny_free(entity_array->entities);
}