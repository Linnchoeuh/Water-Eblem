/**
 ** @file main_menu.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "fe_menu.h"

static void draw_main_menu_buttons(t_game *game,
								   t_main_data *m_data)
{
	t_bunny_position win_center;

	win_center = SETPOS(game->ws->buffer.width / 2,
						game->ws->buffer.height / 2);

	m_data->buttons[0].pos = SETPOS(win_center.x, win_center.y);
	if (draw_button(&game->pic->buffer, &m_data->buttons[0],
					game->mouse, "PLAY"))
		game->menu.current = M_MAP_SELECT;

	m_data->buttons[1].pos = SETPOS(win_center.x, win_center.y + 100);
	if (draw_button(&game->pic->buffer, &m_data->buttons[1],
					game->mouse, "SETTING"))
		game->menu.current = M_SETTINGS;

	m_data->buttons[2].pos = SETPOS(win_center.x, win_center.y + 200);
	if (draw_button(&game->pic->buffer, &m_data->buttons[2],
					game->mouse, "MAP EDITOR"))
		game->menu.current = M_EDITOR_SELECT;

	m_data->buttons[3].pos = SETPOS(win_center.x, win_center.y + 300);
	if (draw_button(&game->pic->buffer, &m_data->buttons[3],
					game->mouse, "QUIT"))
		game->quit = true;
}

void main_menu(t_bunny_buffer *buf,
			   t_game *game)
{
	size_t i;
	t_main_data *menu_data;
	t_button_data *button;

	menu_data = &(game->menu.main_data);
	if (game->menu.current != game->menu.previous)
	{
		switch_music(&game->audio, game->audio.music[MU_MAIN]);
		i = 0;
		while (i < NBR_BUTTON_MAIN_MENU)
		{
			button = &menu_data->buttons[i];
			(*button) = new_button(SETPOS(0, 0),
								   game->font[FS_50], WHITE, NULL);
			button->touched_sound = game->audio.sfx[SFX_MAP_MOVE];
			button->clicked_sound = game->audio.sfx[SFX_VALIDATE];
			button->center_rect = true;
			i++;
		}
		game->menu.previous = game->menu.current;
	}
	draw_str(buf, game->font[FS_100], "WATER EBLEM", SETPOS(10, 10));
	draw_main_menu_buttons(game, menu_data);
}
