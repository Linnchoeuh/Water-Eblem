/**
 ** @file healing.c
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "entities.h"

void healing(t_entity *healer,
             t_entity *target)
{
    int healing;

    if (target->alive == false)
        return;
    if (healer->equiped->type != HEAL_STAFF)
        return;
    printo("\n----HEAL----\n");
    healing = healer->equiped->attack + healer->damage;
    printo("%d hp restored.\n", healing);
        target->health += healing;
    if (target->health > target->max_health)
        target->health = target->max_health;
    printo("Unit team: %d | hp %d/%d\n",
           target->team, target->health, target->max_health);
}