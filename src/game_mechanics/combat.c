/**
 ** @file combat.c
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "fe.h"

static void hit(t_entity *attacker,
                t_entity *defender)
{
    int damage;

    damage = attacker->damage + attacker->equiped->attack - defender->defense;
    if (damage > 0)
    {
        defender->health -= damage;
        printo("%d damage delt\n", damage);
    }
    else
        write(1, "No damage.\n", term_strlen("No damage.\n"));
    if (defender->health <= 0)
        defender->alive = 0;
}

static bool is_dead(t_entity *entity)
{
    if (entity->alive == 0)
    {
        write(1, "He ded\n", term_strlen("He ded\n"));
        return (1);
    }
    return (0);
}

static bool attack_turn(t_entity *attacker,
                        t_entity *defender)
{
    hit(attacker, defender);
    if (is_dead(defender))
        return (1);
    hit(defender, attacker);
    if (is_dead(attacker))
        return (1);
    return (0);
}

void combat(t_entity *attacker,
            t_entity *defender)
{
    bool desabled;

    desabled = false;
    if (defender->equiped == NULL)
        desabled = true;
    else
    {
        if (defender->equiped->range < attacker->equiped->range)
            desabled = true;
        else if (defender->equiped->type == HEAL_STAFF)
            desabled = true;
    }
    if (attacker->speed - 5 >= defender->speed)
    {
        if (attack_turn(attacker, defender))
            return;
    }
    if (attacker->speed >= defender->speed)
    {
        if (attack_turn(attacker, defender))
            return;
    }
    else if (desabled == false)
        attack_turn(defender, attacker);
}

