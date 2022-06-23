/**
 ** @file init_editor_menu.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "fe_menu.h"

void init_editor_menu(t_game *game,
					  t_editor_data *m_data)
{
	size_t i;
	t_button_data *button;

	m_data->name = NULL;
	m_data->mouse = &game->mouse;
	i = 0;
	while (i < NBR_BUTTON_EDIT_MENU)
	{
		button = &m_data->buttons[i];
		(*button) = new_button(SETPOS(0, 0),
			game->font[FS_50], WHITE, NULL);
		button->touched_sound = game->audio.sfx[SFX_MAP_MOVE];
		button->clicked_sound = game->audio.sfx[SFX_VALIDATE];
		i++;
	}
	m_data->any_menu_showed = false;
	m_data->show_collision = true;
	m_data->pause_window = false;
	m_data->tile_window = false;
	m_data->any_tile_button_touched = false;
	m_data->tile_select = NULL;
	m_data->selected_sprite = new_animation_struct(NULL);
	m_data->side_window = false;
	m_data->zoom = 1;
	m_data->zoom_max = 1;
	m_data->pos_1d = 0;
	m_data->tile_pos = SETPOS(0,0);
	m_data->map_layer = false;
	m_data->hide_opposite_map = false;
	m_data->unit_window = false;
	m_data->entity = new_entity(NULL, SWORDSMAN, SETPOS(0,0));
	m_data->block_placing = false;
	m_data->add_entity_request = false;
}