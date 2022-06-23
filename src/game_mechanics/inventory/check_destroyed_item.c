/**
 ** @file check_destroyed_item.c
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "inventory.h"
#include <stddef.h>

void check_destroyed_item(t_weapon *equiped,
                          t_inventory *inv)
{
    int i;
    t_weapon *temp;

    i = 0;
    if (equiped != NULL && equiped->durability <= 0)
        equiped = NULL;
    while (i < inv->nbr_obj)
    {
        if (inv->objs[i].type < NBR_WEAPONS)
        {
            temp = (t_weapon *)inv->objs[i].content;
            if (temp->durability <= 0)
                delete_obj_inventory(inv, i);
        }
        ++i;
    }
}