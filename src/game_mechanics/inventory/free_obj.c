/**
 ** @file free_obj.c
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "fe.h"

void free_obj(t_obj *obj)
{
    t_potion *pot;
    t_weapon *wep;

    if (obj->type == POTION)
    {
        pot = (t_potion*) obj->content;
        if (pot->name != NULL)
            free(pot->name);
    }
    else if (obj->type <= NBR_WEAPONS)
    {
        wep = (t_weapon*) obj->content;
        if (wep->name != NULL)
            free(wep->name);
    }
    obj->content = NULL;
    obj->type = NO_ITEM;
}