/**
 ** @file create_inventory.c
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "fe.h"

t_inventory create_inventory(int max_size)
{
    t_inventory inv;

    inv.max_size = max_size;
    inv.nbr_obj = 0;
    inv.objs = bunny_malloc(sizeof(t_obj) * max_size);
    return (inv);
}