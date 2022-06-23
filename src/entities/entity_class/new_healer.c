/**
 ** @file new_healer.c
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "entities.h"

void new_healer(t_entity *entity)
{
    entity->damage = 1;
    entity->defense = 4;
    entity->max_health = 10;
    entity->health = entity->max_health;
    entity->speed = 1;
    entity->max_movement = 4;
    entity->class = HEALER;
    entity->inventory = create_inventory(DEFAULT_INVENTORY_SIZE);
    add_obj_inventory(&entity->inventory, create_object(HEAL_STAFF, BRONZE));
    entity->equiped = (t_weapon*) entity->inventory.objs->content;
}