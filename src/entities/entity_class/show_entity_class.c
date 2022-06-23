/**
 ** @file show_entity_class.c
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "entities.h"

void show_entity_class(t_entity_array array)
{
    int i;

    i = 0;
    while (i < array.nbr_entities - 1)
    {
        printo("%d : %s", i, array.entities[i].equiped->name);
        ++i;
    }
}