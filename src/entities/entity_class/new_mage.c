/**
 ** @file new_mage.c
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "entities.h"

void new_mage(t_entity *entity)
{
    entity->damage = 5;
    entity->defense = 2;
    entity->max_health = 15;
    entity->health = entity->max_health;
    entity->speed = 4;
    entity->max_movement = 4;
    entity->class = MAGE;
    entity->inventory = create_inventory(DEFAULT_INVENTORY_SIZE);
    add_obj_inventory(&entity->inventory, create_object(SPELL_BOOK, BRONZE));
    entity->equiped = (t_weapon*) entity->inventory.objs->content;
}