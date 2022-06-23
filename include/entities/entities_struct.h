/**
 ** @file entities_struct.h
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#ifndef __ENTITIES_STRUCT_H__
#define __ENTITIES_STRUCT_H__

#include "inventory.h"
#include "animation_struct.h"

#define MAX_TEAMS 2

typedef enum e_entity_class
{
    AXEMAN,
    MAGE,
    BOWMAN,
    HEALER,
    NO_CLASS,
    SPEARMAN,
    SWORDSMAN,
    TOTAL_ENTITY_CLASS
}   t_entity_class;

typedef enum e_entity_sprite
{
    P1_AXE,
    P1_BOOK,
    P1_BOW,
    P1_HEAL,
    P1_IDLE,
    P1_SPEAR,
    P1_SWORD,
    P2_AXE,
    P2_BOOK,
    P2_BOW,
    P2_HEAL,
    P2_IDLE,
    P2_SPEAR,
    P2_SWORD
}               t_entity_sprite;

typedef struct s_entity
{
    t_bunny_position pos;
    int team;
    int damage;
    int health;
    int max_health;
    int defense;
    int speed;
    int max_movement;
    int movement;
    int class;
    bool alive;
    bool played;
    bool attacked;
    t_inventory inventory;
    t_weapon *equiped;
    t_animation *animation;
}   t_entity;

typedef struct s_entity_array
{
    t_entity *entities;
    int nbr_entities;
}   t_entity_array;

#endif