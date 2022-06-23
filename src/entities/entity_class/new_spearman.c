/**
 ** @file new_spearman.c
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "entities.h"

void new_spearman(t_entity *entity)
{
    entity->damage = 3;
    entity->defense = 6;
    entity->max_health = 20;
    entity->health = entity->max_health;
    entity->speed = 3;
    entity->max_movement = 4;
    entity->class = SPEARMAN;
    entity->inventory = create_inventory(DEFAULT_INVENTORY_SIZE);
    add_obj_inventory(&entity->inventory, create_object(SPEAR, BRONZE));
    entity->equiped = (t_weapon*) entity->inventory.objs->content;
}