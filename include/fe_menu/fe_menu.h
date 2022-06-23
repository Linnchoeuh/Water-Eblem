/**
 ** @file fe_menu.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __FE_MENU_H__
#define __FE_MENU_H__

#include <lapin.h>

#include "fe_menu_struct.h"
#include "game_struct.h"
#include "font.h"
#include "bunny_macro.h"
#include "mouse.h"
#include "ui.h"
#include "map.h"
#include "keyboard.h"
#include "audio.h"
#include "dialog.h"
#include "path.h"
#include "range.h"

typedef void (*t_menu_func)(t_bunny_buffer *buf,
							t_game *game);



void undefined_menu(t_bunny_buffer *buf,
					t_game *game);



void main_menu(t_bunny_buffer *buf,
			   t_game *game);



void select_map_menu(t_bunny_buffer *buf,
                     t_game *game);



void play_menu(t_bunny_buffer *buf,
			   t_game *game);

void editor_select_menu(t_bunny_buffer *buf,
						t_game *game);



void setting_menu(t_bunny_buffer *buf,
				  t_game *game);

void init_setting_menu(t_game *game,
					   t_setting_data *m_data);



void editor_menu(t_bunny_buffer *buf,
				 t_game *game);

void init_editor_menu(t_game *game,
					  t_editor_data *m_data);

void delete_editor_menu_content(t_editor_data *m_data);

void display_tile_window(t_bunny_buffer *buf,
						 t_game *game,
						 t_editor_data *menu_data);

void display_pause_window(t_bunny_buffer *buf,
						  t_game *game,
						  t_editor_data *menu_data);

void display_side_window(t_bunny_buffer *buf,
						 t_game *game,
						 t_editor_data *menu_data);

void display_unit_window(t_bunny_buffer *buf,
						 t_game *game,
						 t_editor_data *m_data);

#endif