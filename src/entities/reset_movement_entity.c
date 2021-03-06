/**
 ** @file reset_movement_entity.c
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "entities.h"

void reset_movement_entity(t_entity_array *array)
{
    int i;

    i = 0;
    while (i < array->nbr_entities)
    {
        array->entities[i].moved = false;
        array->entities[i].attacked = false;
        ++i;
    }
}