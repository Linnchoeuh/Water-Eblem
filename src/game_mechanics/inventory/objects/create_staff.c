/**
 ** @file create_staff.c
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "fe.h"

t_weapon create_staff(int type)
{
    t_weapon staff;

    if (type == BRONZE)
    {
        staff.attack = 7;
        staff.max_durability = 10;
        staff.name = term_strdup("Bronze staff");
    }
    else if (type == IRON)
    {
        staff.attack = 9;
        staff.max_durability = 20;
        staff.name = term_strdup("Iron staff");
    }
    else if (type == STEEL)
    {
        staff.attack = 12;
        staff.max_durability = 40;
        staff.name = term_strdup("Steel staff");
    }
    else if (type == SILVER)
    {
        staff.attack = 15;
        staff.max_durability = 25;
        staff.name = term_strdup("Silver staff");
    }
    staff.durability = staff.max_durability;
    staff.range = 1;
    return (staff);
}