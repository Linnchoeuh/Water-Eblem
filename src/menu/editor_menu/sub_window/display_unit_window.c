/**
 ** @file display_unit_window.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "fe_menu.h"

static void change_class_button(t_bunny_buffer *buf,
								t_button_data *button,
								t_game *game,
								t_editor_data *m_data)
{
	draw_str(buf, game->font[FS_50], "CHANGE CLASS", SETPOS(650, 50));
	button[0].pos = SETPOS(550, 50);
	if (draw_button(buf, &button[0], game->mouse, "[<]"))
	{
		m_data->entity.class -= 1;
		if (m_data->entity.class < 0)
			m_data->entity.class = TOTAL_ENTITY_CLASS - 1;
		update_entity_sprite(&m_data->entity, game->map->entities_asset);
	}
	button[1].pos = SETPOS(1000, 50);
	if (draw_button(buf, &button[1], game->mouse, "[>]"))
	{
		m_data->entity.class += 1;
		m_data->entity.class =
			m_data->entity.class % TOTAL_ENTITY_CLASS;
		update_entity_sprite(&m_data->entity, game->map->entities_asset);
	}
}

static void change_team_button(t_bunny_buffer *buf,
								t_button_data *button,
								t_game *game,
								t_editor_data *m_data)
{
	char *tmp_str;

	tmp_str = generate_str("TEAM %d", m_data->entity.team);
	draw_str(buf, game->font[FS_50], tmp_str, SETPOS(650, 150));
	button[0].pos = SETPOS(550, 150);
	if (draw_button(buf, &button[0], game->mouse, "[<]"))
	{
		m_data->entity.team -= 1;
		if (m_data->entity.team < 0)
			m_data->entity.team = MAX_TEAMS - 1;
		update_entity_sprite(&m_data->entity, game->map->entities_asset);
	}
	button[1].pos = SETPOS(850, 150);
	if (draw_button(buf, &button[1], game->mouse, "[>]"))
	{
		m_data->entity.team += 1;
		m_data->entity.team =
			m_data->entity.team % MAX_TEAMS;
		update_entity_sprite(&m_data->entity, game->map->entities_asset);
	}
}

static void display_unit_background(t_bunny_buffer *buf,
									t_button_data *button,
									t_game *game,
									t_editor_data *m_data)
{
	t_bunny_area area;
	unsigned int colors[2];
	t_bunny_position pos[2];

	area = SETAREA(0, 0, buf->width, buf->height);
	draw_full_rect(buf, area, COLOR(220, 0, 0, 0));
	colors[0] = WHITE;
	colors[1] = WHITE;
	pos[0] = SETPOS(500, 0);
	pos[1] = SETPOS(500, buf->height);
	bunny_set_line(buf, pos, colors);
	pos[0] = SETPOS(0, 400);
	pos[1] = SETPOS(500, 400);
	bunny_set_line(buf, pos, colors);
	play_entity_animation(&m_data->entity, 0);
	display_entity(buf, &m_data->entity, SETAREA(100, 50, 300, 300));
	button->pos = SETPOS(buf->width - 110, 0);
	if (draw_button(buf, button, game->mouse, "BACK") ||
		game->keyboard.key_pressed[BKS_ESCAPE])
	{
		game->keyboard.key_pressed[BKS_ESCAPE] = false;
		m_data->unit_window = false;
	}
}

void display_unit_window(t_bunny_buffer *buf,
						 t_game *game,
						 t_editor_data *m_data)
{
	display_unit_background(buf, &m_data->buttons[10], game, m_data);
	change_class_button(buf, &m_data->buttons[11], game, m_data);
	change_team_button(buf, &m_data->buttons[13], game, m_data);
	m_data->buttons[15].pos = SETPOS(700, buf->height - 150);
	m_data->buttons[15].font = game->font[FS_150];
	if (draw_button(buf, &m_data->buttons[15], game->mouse, "DONE"))
	{

		change_animation_sprite(m_data->selected_sprite,
			m_data->entity.animation->sprite);
		m_data->block_placing = true;
		m_data->unit_window = false;
	}
}