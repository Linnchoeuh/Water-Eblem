/**
 ** @file change_equiped_weapon.c
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "inventory.h"

t_weapon *change_equiped_weapon(t_weapon *equiped, 
                                t_inventory *inv,
                                int pos)
{
    if (pos > inv->nbr_obj - 1)
        return (equiped);
    if (inv->objs[pos].type >= NBR_WEAPONS)
        return (equiped);
    return((t_weapon*) inv->objs[pos].content);
}