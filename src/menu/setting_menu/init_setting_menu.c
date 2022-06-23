/**
 ** @file init_setting_menu.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "fe_menu.h"

void init_setting_menu(t_game *game,
					  t_setting_data *m_data)
{
	size_t i;
	t_button_data *button;

	i = 0;
	while (i < NBR_BUTTON_SETTING_MENU)
	{
		button = &m_data->buttons[i];
		(*button) = new_button(SETPOS(0, 0),
			game->font[FS_30], WHITE, NULL);
		button->touched_sound = game->audio.sfx[SFX_MAP_MOVE];
		button->clicked_sound = game->audio.sfx[SFX_VALIDATE];
		i++;
	}
}