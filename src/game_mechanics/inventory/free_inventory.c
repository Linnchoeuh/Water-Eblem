/**
 ** @file free_inventory.c
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "fe.h"

void free_inventory(t_inventory *inv)
{
    int i;

    i = 0;
    while (i < inv->nbr_obj)
    {
        free_obj(&inv->objs[i]);
        ++i;
    }
    inv->nbr_obj = 0;
    bunny_free(inv->objs);
}