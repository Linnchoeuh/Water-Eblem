/**
 ** @file new_bowman.c
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "entities.h"

void new_bowman(t_entity *entity)
{
    entity->damage = 4;
    entity->defense = 2;
    entity->max_health = 12;
    entity->health = entity->max_health;
    entity->speed = 5;
    entity->max_movement = 5;
    entity->class = BOWMAN;
    entity->inventory = create_inventory(DEFAULT_INVENTORY_SIZE);
    add_obj_inventory(&entity->inventory, create_object(BOW, BRONZE));
    entity->equiped = (t_weapon*) entity->inventory.objs->content;
}