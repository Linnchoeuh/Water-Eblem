/**
 ** @file create_spear.c
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "fe.h"

t_weapon create_spear(int type)
{
    t_weapon spear;

    if (type == BRONZE)
    {
        spear.attack = 3;
        spear.max_durability = 10;
        spear.name = term_strdup("Bronze spear");
    }
    else if (type == IRON)
    {
        spear.attack = 4;
        spear.max_durability = 25;
        spear.name = term_strdup("Iron spear");
    }
    else if (type == STEEL)
    {
        spear.attack = 6;
        spear.max_durability = 40;
        spear.name = term_strdup("Steel spear");
    }
    else if (type == SILVER)
    {
        spear.attack = 8;
        spear.max_durability = 30;
        spear.name = term_strdup("Silver spear");
    }
    spear.durability = spear.max_durability;
    spear.range = 1;
    return (spear);
}