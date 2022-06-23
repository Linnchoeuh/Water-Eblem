/**
 ** @file delete_entity.h
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "entities.h"
#include "inventory.h"

bool delete_entity(t_entity *entity)
{
    free_inventory(&entity->inventory);
    delete_animation_struct(entity->animation);
    return (true);
}