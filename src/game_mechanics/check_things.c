/**
 ** @file check_things.c
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "entities.h"

void check_things(t_entity_array *array)
{
    int i;
    
    i = 0;
    while (i < array->nbr_entities - 1)
    {
        if (array->entities[i].alive == 0 || array->entities[i].health <= 0)
            remove_entity(array, i);
        else
            check_destroyed_item(array->entities[i].equiped, &array->entities->inventory);
        ++i;
    }
}