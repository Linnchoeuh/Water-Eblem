/**
 ** @file new_axeman.c
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "entities.h"

void new_axeman(t_entity *entity)
{
    entity->damage = 5;
    entity->defense = 0;
    entity->max_health = 20;
    entity->health = entity->max_health;
    entity->speed = 4;
    entity->max_movement = 4;
    entity->class = AXEMAN;
    entity->inventory = create_inventory(DEFAULT_INVENTORY_SIZE);
    add_obj_inventory(&entity->inventory, create_object(AXE, BRONZE));
    entity->equiped = (t_weapon*) entity->inventory.objs->content;
}