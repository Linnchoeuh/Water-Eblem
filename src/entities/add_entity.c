/**
 ** @file add_entity.c
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "entities.h"

bool add_entity(t_entity_array *array,
                t_entity entity)
{
    array->nbr_entities += 1;
    array->entities = realloc(array->entities,
        sizeof(t_entity) * array->nbr_entities);
    if (array->entities == NULL)
        return (false);
    array->entities[array->nbr_entities - 1] = entity;
    return (true);
}