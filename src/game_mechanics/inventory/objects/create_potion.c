/**
 ** @file create_potion.c
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "fe.h"

t_potion create_potions(void)
{
    t_potion pot;

    pot.heal_value = 10;
    pot.durability = 3;
    pot.name = term_strdup("Potion");
    return (pot);
}