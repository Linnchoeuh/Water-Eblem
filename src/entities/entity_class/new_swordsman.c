/**
 ** @file new_swordsman.c
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "entities.h"

void new_swordsman(t_entity *entity)
{
    entity->damage = 3;
    entity->defense = 3;
    entity->max_health = 15;
    entity->health = entity->max_health;
    entity->speed = 8;
    entity->max_movement = 5;
    entity->class = SWORDSMAN;
    add_obj_inventory(&entity->inventory, create_object(SWORD, BRONZE));
    entity->equiped = (t_weapon*) entity->inventory.objs->content;
}