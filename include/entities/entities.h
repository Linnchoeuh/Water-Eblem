/**
 ** @file entities.h
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#ifndef __ENTITIES_H__
#define __ENTITIES_H__

#include "entities_struct.h"
#include "animation.h"
#include "tile_struct.h"
#include "bunny_macro.h"
#include "fe_menu.h"

t_entity_array new_entity_array(void);

bool add_entity(t_entity_array *array,
                t_entity entity);

void display_entity_array(t_bunny_buffer *buf,
                          t_entity_array *entity_array,
                          t_tile_camera cam,
                          t_play_data *m_data);

void display_entity(t_bunny_buffer *buf,
                    t_entity *entity,
                    t_bunny_area area);

bool remove_entity(t_entity_array *entity_array,
                   int pos);

t_entity find_entity(t_entity_array *array,
                      t_bunny_position pos,
                      int *entity_pos);

bool delete_entity(t_entity *entity);

void delete_entity_array(t_entity_array *entity_array);

void play_entity_array_animation(t_entity_array *entity_array,
                                 t_bunny_time time);

void play_entity_animation(t_entity *entity,
                           t_bunny_time time);

void healing(t_entity *healer,
             t_entity *target);

void combat(t_entity *attacker,
            t_entity *defender);

void check_things(t_entity_array *array);

void reset_movement_entity(t_entity_array *array);

/* Use this function to create or initiate your entity.
   spirte is its skin, unit_class is its class (see "t_entity_class" enum) and pos is its position.
   The function also gives a base lowtier weapon to the entity.
*/
t_entity new_entity(t_animation *anim,
                    int unit_class,
                    t_bunny_position pos);

void show_entity_class(t_entity_array array);

// There should not be any need to use functions below.

void new_swordsman(t_entity *entity);

void new_axeman(t_entity *entity);

void new_bowman(t_entity *entity);

void new_spearman(t_entity *entity);

void new_mage(t_entity *entity);

void new_healer(t_entity *entity);

void update_entity_sprite(t_entity *entity,
                          t_sprite_bank *entities_asset);

#endif