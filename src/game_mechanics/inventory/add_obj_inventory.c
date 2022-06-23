/**
 ** @file create_inventory.c
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "fe.h"

t_inventory add_obj_inventory(t_inventory *inv,
                              t_obj obj)
{
    if(inv->nbr_obj < inv->max_size)
        inv->objs[inv->nbr_obj] = obj;
    ++inv->nbr_obj;
    return (*inv);
}