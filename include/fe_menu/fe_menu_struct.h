/**
 ** @file fe_menu_struct.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __FE_MENU_STRUCT_H__
#define __FE_MENU_STRUCT_H__

#include <lapin.h>

#include "map_struct.h"
#include "mouse_struct.h"
#include "ui_struct.h"

#define NBR_BUTTON_MAIN_MENU 4
#define NBR_BUTTON_SETTING_MENU 7
#define NBR_BUTTON_EDIT_SELECT_MENU 7
#define NBR_BUTTON_EDIT_MENU 17
#define NBR_BUTTON_MAP_SELECT_MENU 1

typedef enum 	e_menus
{
	M_MAIN,
	M_MAP_SELECT,
	M_GAME,
	M_SETTINGS,
	M_EDITOR_SELECT,
	M_EDITOR,
	M_ALL_MENU
}				t_menus;

typedef enum 	e_new_map_entry
{
	E_NONE,
	E_NAME,
	E_WIDTH,
	E_HEIGHT
}				t_new_map_entry;

typedef struct	s_main_data
{
	t_button_data buttons[NBR_BUTTON_MAIN_MENU];
}				t_main_data;

typedef struct	s_play_data
{
	bool game_turn;
	t_entity *selected_entity;
	t_mouse *mouse;
	t_bunny_position prev_pos;
}				t_play_data;

typedef struct	s_setting_data
{
	t_button_data buttons[NBR_BUTTON_SETTING_MENU];
}				t_setting_data;

typedef struct	s_select_map_data
{
	t_button_data buttons[NBR_BUTTON_SETTING_MENU];
}				t_select_map_data;

typedef struct	s_editor_select_data
{
	int edited_entry;
	bool show_sub_window;
	char *name;
	t_button_data buttons[NBR_BUTTON_EDIT_SELECT_MENU];
	t_bunny_position map_size;
}				t_editor_select_data;

typedef struct	s_editor_data
{
	char *name;
	t_mouse *mouse;
	t_animation *selected_sprite;
	t_button_data buttons[NBR_BUTTON_EDIT_MENU];
	bool any_menu_showed;
	bool show_collision;

	bool pause_window;

	bool tile_window;
	bool any_tile_button_touched;
	t_tile_array *tile_select;
	bool block_placing;

	bool side_window;
	double zoom;
	double zoom_max;
	unsigned int pos_1d;
	t_bunny_position tile_pos;
	bool map_layer;
	bool hide_opposite_map;

	bool unit_window;
	t_entity entity;
	bool add_entity_request;
}				t_editor_data;


typedef struct	s_menu
{
	int current;
	int previous;
	t_main_data main_data;
	t_select_map_data select_map_data;
	t_play_data play_data;
	t_setting_data setting_data;
	t_editor_select_data editor_select_data;
	t_editor_data editor_data;
}				t_menu;

#endif