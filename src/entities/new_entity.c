/**
 ** @file new_entity.h
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "entities.h"
#include "bunny_macro.h"

t_entity new_entity(t_animation *anim,
                    int unit_class,
                    t_bunny_position pos)
{
    t_entity entity;

    entity.alive = 1;
    entity.pos = pos;
    entity.team = 0;
    entity.class = unit_class;
    entity.animation = anim;
    entity.attacked = 0;
    entity.inventory = create_inventory(INVENTORY_SIZE);
    entity.equiped = NULL;
    if (unit_class == SWORDSMAN)
        new_swordsman(&entity);
    else if (unit_class == AXEMAN)
        new_axeman(&entity);
    else if (unit_class == SPEARMAN)
        new_spearman(&entity);
    else if (unit_class == BOWMAN)
        new_bowman(&entity);
    else if (unit_class == MAGE)
        new_mage(&entity);
    else if (unit_class == HEALER)
        new_healer(&entity);
    return (entity);
}