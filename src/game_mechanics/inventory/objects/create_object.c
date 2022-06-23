/**
 ** @file create_object.c
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "fe.h"

t_obj create_object(int obj_type,
                    int obj_tier)
{
    t_obj obj;
    t_weapon *tmp_weapon;
    t_potion *tmp_potion;

    obj.type = obj_type;
    if (obj_type < NBR_WEAPONS)
    {
        tmp_weapon = bunny_malloc(sizeof(t_weapon));
        *tmp_weapon = create_weapon(obj_type, obj_tier);
        obj.content = tmp_weapon;
    }
    else
    {
        tmp_potion = bunny_malloc(sizeof(t_potion));
        *tmp_potion = create_potions();
        obj.content = &tmp_potion;
    }
    return (obj);
}

