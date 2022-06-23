/**
 ** @file global.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "global.h"

const int FONT_SIZE[FS_TOTAL] = {15, 20, 30, 40, 50, 100, 150};

const t_menu_func MENUS[M_ALL_MENU] = {
	main_menu,
	select_map_menu,
	play_menu,
	setting_menu,
	editor_select_menu,
	editor_menu
};