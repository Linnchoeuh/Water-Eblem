/**
 ** @file editor_select_menu.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "fe_menu.h"

bool get_entry(t_game *game,
			   t_button_data *button,
			   char **edited_value,
			   bool enable_read)
{
	t_bunny_buffer *buf;
	t_editor_select_data *menu_data;

	menu_data = &game->menu.editor_select_data;
	buf = &game->pic->buffer;
	button->rect_size = SETPOS(buf->width - 280, 20);
	button->size_rect_to_text = false;
	button->font = game->font[FS_20];
	button->idle_color = COLOR(255, 192, 192, 192);
	button->touched_color = COLOR(255, 255, 255, 255);
	button->clicked_color = COLOR(255, 0, 0, 255);
	if (draw_button(&game->pic->buffer, button,
		game->mouse, *edited_value))
		return (true);
	if (enable_read)
	{
		read_entry(&game->keyboard, edited_value,
			menu_data->edited_entry != E_NAME);
		draw_rect(&game->pic->buffer,
			SETAREA(button->pos.x, button->pos.y,
				button->rect_size.x, button->rect_size.y),
			button->clicked_color);
		if (game->keyboard.key_pressed[BKS_ESCAPE])
		{
			game->keyboard.key_pressed[BKS_ESCAPE] = false;
			menu_data->edited_entry = E_NONE;
		}
	}
	return (false);
}

void display_editor_sub_window(t_bunny_buffer *buf,
							   t_game *game,
							   t_editor_select_data *m_data)
{
	char *tmp;
	t_bunny_area area;

	area = SETAREA(0, 0, buf->width, buf->height);
	draw_full_rect(buf, area, COLOR(128, 0, 0, 0));
	area = SETAREA(100, 100, buf->width - 200, buf->height - 200);
	draw_full_rect(buf, area, BLACK);
	draw_rect(buf, area, WHITE);

	m_data->buttons[2].pos = SETPOS(buf->width - 250, 110);
	set_button_color_set(&m_data->buttons[2], COLOR(255, 255, 0, 0));
	m_data->buttons[2].clicked_sound = game->audio.sfx[SFX_BACK1];
	if (draw_button(buf, &m_data->buttons[2], game->mouse, "CLOSE") ||
		(game->keyboard.key_pressed[BKS_ESCAPE] &&
		m_data->edited_entry == E_NONE))
	{
		m_data->edited_entry = E_NONE;
		game->keyboard.key_pressed[BKS_ESCAPE] = false;
		m_data->show_sub_window = false;
		game->mouse.button_pressed[BMB_LEFT] = false;
	}
	draw_str(&game->pic->buffer, game->font[FS_50],
		"NAME", SETPOS(140, 200));

	m_data->buttons[3].pos = SETPOS(160, 260);
	if (get_entry(game, &m_data->buttons[3],
		&m_data->name, m_data->edited_entry == E_NAME))
		m_data->edited_entry = E_NAME;

	draw_str(&game->pic->buffer, game->font[FS_50],
		"WIDTH", SETPOS(140, 300));
	tmp = generate_str("%d", m_data->map_size.x);
	m_data->buttons[4].pos = SETPOS(160, 360);
	if (get_entry(game, &m_data->buttons[4],
		&tmp, m_data->edited_entry == E_WIDTH))
		m_data->edited_entry = E_WIDTH;
	if (tmp != NULL)
	{
		if (tmp[0] == '\0')
			m_data->map_size.x = 0;
		else
			m_data->map_size.x = std_atoi(tmp);
		if (m_data->map_size.x > 1000)
			m_data->map_size.x = 1000;
		free(tmp);
	}


	draw_str(&game->pic->buffer, game->font[FS_50],
		"HEIGHT", SETPOS(140, 400));
	tmp = generate_str("%d", m_data->map_size.y);
	m_data->buttons[5].pos = SETPOS(160, 460);
	if (get_entry(game, &m_data->buttons[5],
		&tmp, m_data->edited_entry == E_HEIGHT))
		m_data->edited_entry = E_HEIGHT;
	if (tmp != NULL)
	{
		if (tmp[0] == '\0')
			m_data->map_size.y = 0;
		else
			m_data->map_size.y = std_atoi(tmp);
		if (m_data->map_size.y > 1000)
			m_data->map_size.y = 1000;
		free(tmp);
	}

	set_button_color_set(&m_data->buttons[6], COLOR(255, 0, 255, 0));
	m_data->buttons[6].pos = SETPOS(buf->width / 2, buf->height - 170);
	m_data->buttons[6].font = game->font[FS_100];
	m_data->buttons[6].center_rect = true;
	if (draw_button(buf, &m_data->buttons[6], game->mouse, "DONE"))
	{
		m_data->edited_entry = E_NONE;
		game->menu.current = M_EDITOR;
	}
}

void editor_select_menu(t_bunny_buffer *buf,
				 		t_game *game)
{
	size_t i;
	t_button_data *button;
	t_editor_select_data *m_data;

	m_data = &(game->menu.editor_select_data);
	if (game->menu.current != game->menu.previous)
	{

        if (game->map_list == NULL)
            game->map_list = create_map_list(MAP_PATH);
		m_data->edited_entry = E_NONE;
		m_data->name = term_strdup("My_map");
		m_data->show_sub_window = false;
		m_data->map_size = SETPOS(9, 9);
		i = 0;
		while (i < NBR_BUTTON_EDIT_SELECT_MENU)
		{
			button = &m_data->buttons[i];
			(*button) = new_button(SETPOS(0, 0),
				game->font[FS_50], WHITE, NULL);
			button->touched_sound = game->audio.sfx[SFX_MAP_MOVE];
			button->clicked_sound = game->audio.sfx[SFX_VALIDATE];
			i++;
		}
		switch_music(&game->audio, game->audio.music[MU_MAIN]);
		game->menu.previous = game->menu.current;
		reset_conv_status(game->conv);
	}
	m_data->buttons[0].pos = SETPOS(buf->width - 100, 10);
	set_button_color_set(&m_data->buttons[0], COLOR(255, 0, 255, 0));
	if (draw_button(buf, &m_data->buttons[0], game->mouse, "NEW"))
		m_data->show_sub_window = true;
	game->map_list->disable_buttons = m_data->show_sub_window;
	if (display_map_list(buf, game->map_list, game, 70))
    {
		m_data->name = term_strdup(game->map_list->taken_name);
		printo("%s\n", m_data->name);
        delete_map_list(game->map_list);
        game->map_list = NULL;
        game->menu.current = M_EDITOR;
    }
	m_data->buttons[1].pos = SETPOS(10, 10);
	m_data->buttons[1].clicked_sound = game->audio.sfx[SFX_BACK1];
	if (draw_button(buf, &m_data->buttons[1], game->mouse, "BACK"))
	{
		bunny_free(m_data->name);
		m_data->name = NULL;
		delete_map_list(game->map_list);
        game->map_list = NULL;
		game->menu.current = M_MAIN;
	}
	if (m_data->show_sub_window)
		display_editor_sub_window(buf, game, m_data);

	// display_conv(buf, game->conv, game->mouse.button_pressed[BMB_LEFT], game->fps.delta_time);
}