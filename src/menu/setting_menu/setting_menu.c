/**
 ** @file setting_menu.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "fe_menu.h"

void draw_volume_value(t_bunny_buffer *buf,
					   double *volume_value,
					   t_bunny_position pos,
					   t_bunny_font *font)
{
	char *tmp_str;

	if (*volume_value < 0)
		*volume_value = 0;
	if (*volume_value > 100)
		*volume_value = 100;
	tmp_str = generate_str("%d", (long) (*volume_value));
	if (tmp_str != NULL)
	{
		draw_str(buf, font, tmp_str, pos);
		bunny_free(tmp_str);
	}
}

double volume_buttons(t_bunny_buffer *buf,
				   t_game *game,
				   t_bunny_position pos,
				   t_button_data *buttons)
{
	double return_value;

	buttons[0].pos = pos;
	set_button_color_set(&buttons[0], RED);
	buttons[1].pos = SETPOS(pos.x + 150, pos.y);
	set_button_color_set(&buttons[1], GREEN);
	return_value = 0;
	return_value -= 5 * (draw_button(buf, &buttons[0], game->mouse, "[-]"));
	return_value += 5 * (draw_button(buf, &buttons[1], game->mouse, "[+]"));
	return (return_value);
}

void draw_volume_buttons(t_bunny_buffer *buf,
				  		 t_game *game,
						 t_setting_data *m_data)
{
	t_bunny_position tmp_pos;

	tmp_pos = SETPOS(50, 100);
	draw_str(buf, game->font[FS_50], "MASTER", tmp_pos);
	tmp_pos = SETPOS(tmp_pos.x + 50, tmp_pos.y + 60);
	game->audio.master_vol +=
		volume_buttons(buf, game, tmp_pos, &m_data->buttons[1]);
	tmp_pos.x += 75;
	draw_volume_value(buf, &game->audio.master_vol, tmp_pos, game->font[FS_30]);

	tmp_pos = SETPOS((buf->width / 2) - 90, 100);
	draw_str(buf, game->font[FS_50], "MUSIC", tmp_pos);
	tmp_pos = SETPOS(tmp_pos.x + 50, tmp_pos.y + 60);
	game->audio.music_vol +=
		volume_buttons(buf, game, tmp_pos, &m_data->buttons[3]);
	tmp_pos.x += 75;
	draw_volume_value(buf, &game->audio.music_vol, tmp_pos, game->font[FS_30]);

	tmp_pos = SETPOS(buf->width - 280, 100);
	draw_str(buf, game->font[FS_50], "SFX", tmp_pos);
	tmp_pos = SETPOS(tmp_pos.x + 50, tmp_pos.y + 60);
	game->audio.sfx_vol +=
		volume_buttons(buf, game, tmp_pos, &m_data->buttons[5]);
	tmp_pos.x += 75;
	draw_volume_value(buf, &game->audio.sfx_vol, tmp_pos, game->font[FS_30]);
}

void setting_menu(t_bunny_buffer *buf,
				  t_game *game)
{
	t_setting_data *m_data;

	m_data = &(game->menu.setting_data);
	if (game->menu.current != game->menu.previous)
	{
		init_setting_menu(game, m_data);
		game->menu.previous = game->menu.current;
		m_data->buttons[0].clicked_sound = game->audio.sfx[SFX_BACK1];
	}
	m_data->buttons[0].font = game->font[FS_50];
	m_data->buttons[0].pos = SETPOS(0, 0);
	if (draw_button(buf, &m_data->buttons[0], game->mouse, "BACK"))
	{
		game->menu.current = M_MAIN;
	}
	draw_volume_buttons(buf, game, m_data);
	update_volume(&game->audio);
}