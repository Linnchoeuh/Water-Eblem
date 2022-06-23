/**
 ** @file create_bow.c
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "fe.h"

t_weapon create_bow(int type)
{
    t_weapon bow;

    if (type == BRONZE)
    {
        bow.attack = 3;
        bow.max_durability = 10;
        bow.name = term_strdup("Bronze bow");
    }
    else if (type == IRON)
    {
        bow.attack = 5;
        bow.max_durability = 20;
        bow.name = term_strdup("Iron bow");
    }
    else if (type == STEEL)
    {
        bow.attack = 7;
        bow.max_durability = 40;
        bow.name = term_strdup("Steel bow");
    }
    else if (type == SILVER)
    {
        bow.attack = 10;
        bow.max_durability = 25;
        bow.name = term_strdup("Silver bow");
    }
    bow.durability = bow.max_durability;
    bow.range = 2;
    return (bow);
}