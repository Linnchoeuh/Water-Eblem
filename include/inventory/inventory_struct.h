/**
 ** @file inventory_struct.h
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#ifndef __INVENTORY_STRUCT_H__
#define __INVENTORY_STRUCT_H__

#define DEFAULT_INVENTORY_SIZE 4

//Enum used to ease the use of the different weapons type
typedef enum e_weapon_type
{
    NO_ITEM = -1,
    SWORD,
    AXE,
    SPEAR,
    BOW,
    SPELL_BOOK,
    HEAL_STAFF,
    NBR_WEAPONS,
    POTION
}   t_weapon_type;

//Enum used to ease the use of the different weapons tiers
typedef enum e_weapon_tier
{
    BRONZE,
    IRON,
    STEEL,
    SILVER,
    NETHERITE,
}   t_weapon_tier;

typedef struct s_weapon
{
    char *name;
    int type;
    int tier;
    int attack;
    int range;
    int max_durability;
    int durability;
}   t_weapon;

typedef struct s_potion
{
    int heal_value;
    int durability;
    char *name;
}   t_potion;

//Void* is used so we can save t_weapons and t_potions all the same. type is used to know what's what.
typedef struct s_obj
{
    int type;
    void *content;
}   t_obj;

typedef struct s_inventory
{
    t_obj *objs;
    int nbr_obj;
    int max_size;
}   t_inventory;

#endif