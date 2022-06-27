/**
 ** @file create_sword.c
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "fe.h"

t_weapon create_sword(int type)
{
    t_weapon sword;

    if (type == BRONZE)
    {
        sword.attack = 3;
        sword.max_durability = 10;
        sword.name = term_strdup("Bronze sword");
    }
    else if (type == IRON)
    {
        sword.attack = 5;
        sword.max_durability = 20;
        sword.name = term_strdup("Iron sword");
    }
    else if (type == STEEL)
    {
        sword.attack = 7;
        sword.max_durability = 40;
        sword.name = term_strdup("Steel sword");
    }
    else if (type == SILVER)
    {
        sword.attack = 10;
        sword.max_durability = 25;
        sword.name = term_strdup("Silver sword");
    }
    sword.durability = sword.max_durability;
    sword.range[MIN_RANGE] = 1;
    sword.range[MAX_RANGE] = 1;
    return (sword);
}