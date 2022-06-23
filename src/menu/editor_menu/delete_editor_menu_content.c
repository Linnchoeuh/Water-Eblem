/**
 ** @file delete_editor_menu_content.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "fe_menu.h"

void delete_editor_menu_content(t_editor_data *m_data)
{
	if (m_data->name != NULL)
		bunny_free(m_data->name);
	m_data->name = NULL;
	delete_tile_array(m_data->tile_select);
	m_data->tile_select = NULL;
	delete_animation_struct(m_data->selected_sprite);
	m_data->selected_sprite = NULL;
}