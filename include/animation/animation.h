/**
 ** @file animation.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include <lapin.h>

#include "animation_struct.h"
#include "sprite_struct.h"
#include "framerate.h"
#include "libstd.h"

t_animation *new_animation_struct(t_sprite *sprite);

void change_animation_sprite(t_animation *anim,
							 t_sprite *sprite);

void play_animation(t_animation *anim,
					t_bunny_time time);

void reset_animation_data(t_animation *anim);

void display_animation(t_bunny_buffer *buf,
					   t_animation *anim,
					   t_bunny_area area);

void delete_animation_struct(t_animation *animation);

void pause_animation(t_animation *animation);

void stop_animation(t_animation *animation);


#endif