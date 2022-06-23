/**
 ** @file remove_entity.h
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "entities.h"
#include "inventory.h"

bool remove_entity(t_entity_array *entity_array,
                   int pos)
{
    t_entity *entities;

    if (pos >= entity_array->nbr_entities)
        return (false);
    entities = bunny_malloc(entity_array->nbr_entities * sizeof(t_entity));
	if (entities == NULL)
		return (false);
	memcpy(entities, entity_array->entities, pos * sizeof(t_entity));
	memcpy(&entities[pos], &entity_array->entities[pos + 1],
		(entity_array->nbr_entities - pos - 1) * sizeof(t_entity));
    delete_entity(&entity_array->entities[pos]);
	entity_array->nbr_entities -= 1;
	bunny_free(entity_array->entities);
	entity_array->entities = entities;
    return (true);
}