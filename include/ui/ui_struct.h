/**
 ** @file ui_struct.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __UI_STRUCT_H__
#define __UI_STRUCT_H__

#include <lapin.h>

#include "mouse_struct.h"
#include "libstd.h"

typedef struct	s_button_data
{
	bool disable_button;
	t_bunny_position pos;
	t_bunny_font *font;
	unsigned int idle_color;
	unsigned int touched_color;		// set_new_map(game, m_data);
		// switch_music(&game->audio, game->audio.music[MU_EDITOR]);
		// m_data->buttons[5].clicked_sound = game->audio.sfx[SFX_BACK1];
		// m_data->buttons[6].clicked_sound = game->audio.sfx[SFX_BACK1];
		// m_data->buttons[7].clicked_sound = game->audio.sfx[SFX_BACK1];		// set_new_map(game, m_data);
		// switch_music(&game->audio, game->audio.music[MU_EDITOR]);
		// m_data->buttons[5].clicked_sound = game->audio.sfx[SFX_BACK1];
		// m_data->buttons[6].clicked_sound = game->audio.sfx[SFX_BACK1];
		// m_data->buttons[7].clicked_sound = game->audio.sfx[SFX_BACK1];
	unsigned int clicked_color;
	bool center_rect;
	bool size_rect_to_text;
	t_bunny_position rect_size;
	bool center_text;
	t_bunny_music *touched_sound;
	t_bunny_music *clicked_sound;
	bool already_touched;
}				t_button_data;

#endif