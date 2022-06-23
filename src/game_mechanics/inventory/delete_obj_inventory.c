/**
 ** @file create_inventory.c
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "fe.h"

t_inventory delete_obj_inventory(t_inventory *inv,
                                 int obj)
{
    if (obj >= inv->nbr_obj)
        return (*inv);
    free_obj(&inv->objs[obj]);
    while(obj < inv->nbr_obj)
    {
        inv->objs[obj] = inv->objs[obj + 1];
        ++obj;
    }
    --inv->nbr_obj;
    return (*inv);
}