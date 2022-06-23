/**
 ** @file inventory.h
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include "inventory_struct.h"

t_inventory create_inventory(int max_size);

void free_inventory(t_inventory *inv);

t_inventory add_obj_inventory(t_inventory *inv,
                              t_obj obj);

t_inventory delete_obj_inventory(t_inventory *inv,
                                 int obj);

// Use this function to create your "t_weapon_type" weapon with OBJ_TIER tier (see the "t_weapon_tier" enum)
t_obj create_object(int obj_type,
                    int obj_tier);

void free_obj(t_obj *obj);

void check_destroyed_item(t_weapon *equiped,
                          t_inventory *inv);

t_weapon *change_equiped_weapon(t_weapon *equiped,
                                t_inventory *inv,
                                int pos);

// No need to use the functions below.

t_potion create_potions();

t_weapon create_weapon(int type,
                       int weapon_tier);

t_weapon create_sword(int type);

t_weapon create_axe(int type);

t_weapon create_bow(int type);

t_weapon create_spear(int type);

t_weapon create_spellbook(int type);

t_weapon create_staff(int type);

#endif