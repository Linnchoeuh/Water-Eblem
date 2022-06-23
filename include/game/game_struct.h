/**
 ** @file struct.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __GAME_STRUCT_H__
#define __GAME_STRUCT_H__

#include <lapin.h>

#include "mouse_struct.h"
#include "keyboard_struct.h"
#include "fe_menu_struct.h"
#include "map_struct.h"
#include "font_struct.h"
#include "framerate_struct.h"
#include "key_input.h"
#include "audio_struct.h"

#include "dialog_struct.h"

#include "bunny_macro.h"

// #include "animation_struct.h"
// #include "sprite_struct.h"

typedef struct	s_game
{
	t_bunny_window *ws;
	t_bunny_picture *pic;
	t_mouse mouse;
	t_keyboard keyboard;
	t_key_input key_input;
	t_menu menu;
	t_map *map;
	bool quit;
	t_bunny_font *font[FS_TOTAL];
	t_framerate fps;
	t_audio audio;
	t_conv *conv;
	t_map_list *map_list;
}				t_game;


#endif