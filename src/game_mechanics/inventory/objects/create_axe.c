/**
 ** @file create_axe.c
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "fe.h"

t_weapon create_axe(int type)
{
    t_weapon axe;

    if (type == BRONZE)
    {
        axe.attack = 5;
        axe.max_durability = 10;
        axe.name = term_strdup("Bronze axe");
    }
    else if (type == IRON)
    {
        axe.attack = 7;
        axe.max_durability = 20;
        axe.name = term_strdup("Iron axe");
    }
    else if (type == STEEL)
    {
        axe.attack = 10;
        axe.max_durability = 40;
        axe.name = term_strdup("Steel axe");
    }
    else if (type == SILVER)
    {
        axe.attack = 15;
        axe.max_durability = 25;
        axe.name = term_strdup("Silver axe");
    }
    axe.durability = axe.max_durability;
    axe.range[MIN_RANGE] = 1;
    axe.range[MAX_RANGE] = 1;
    return (axe);
}