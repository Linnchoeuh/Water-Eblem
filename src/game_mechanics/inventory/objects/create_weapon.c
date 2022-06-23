/**
 ** @file create_weapon.c
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "fe.h"

t_weapon create_weapon(int type,
                       int weapon_tier)
{
    t_weapon weapon;

    if (type == SWORD)
        weapon = create_sword(weapon_tier);
    else if (type == AXE)
        weapon = create_axe(weapon_tier);
    else if (type == BOW)
        weapon = create_bow(weapon_tier);
    else if (type == SPEAR)
        weapon = create_spear(weapon_tier);
    else if (type == SPELL_BOOK)
        weapon = create_spellbook(weapon_tier);
    else if (type == HEAL_STAFF)
        weapon = create_staff(weapon_tier);
    weapon.type = type;
    weapon.tier = weapon_tier;
    return (weapon);
}