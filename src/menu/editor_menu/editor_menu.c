/**
 ** @file editor_menu.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "fe_menu.h"

#define CHECK_ANY_WINDOW_SHOWED(__menu_data) ( \
	(__menu_data)->pause_window ||             \
	(__menu_data)->side_window ||              \
	(__menu_data)->tile_window ||              \
	(__menu_data)->unit_window)

void display_buttons(t_bunny_buffer *buf,
					 t_game *game,
					 t_editor_data *m_data,
					 bool any_menu_showed)
{

	m_data->buttons[0].disable_button = any_menu_showed;
	if ((draw_button(buf, &m_data->buttons[0], game->mouse, "MENU") ||
		 game->keyboard.key_pressed[BKS_ESCAPE]))
	{
		game->keyboard.key_pressed[BKS_ESCAPE] = false;
		m_data->pause_window = true;
	}

	m_data->buttons[1].pos = SETPOS(0, 100);
	m_data->buttons[1].disable_button = any_menu_showed;
	if (draw_button(buf, &m_data->buttons[1], game->mouse, "TILES"))
	{
		game->mouse.button_pressed[BMB_LEFT] = false;
		m_data->tile_window = true;
	}

	m_data->buttons[2].pos = SETPOS(0, 200);
	m_data->buttons[2].disable_button = any_menu_showed;
	if (draw_button(buf, &m_data->buttons[2], game->mouse, "UNITS"))
	{
		game->mouse.button_pressed[BMB_LEFT] = false;
		m_data->unit_window = true;
	}
}

void display_down_bar(t_bunny_buffer *buf,
					  t_game *game,
					  t_editor_data *m_data)
{
	char *tmp_str;
	t_bunny_position pos;

	play_animation(m_data->selected_sprite, 0);
	display_animation(buf, m_data->selected_sprite,
					  SETAREA(10, buf->height - 90, 80, 80));
	pos = SETPOS(100, buf->height - 25);
	pos.x += draw_str(buf, game->font[FS_20], "ROTATE : R", pos);
	tmp_str = generate_str("[%d]",
						   (int)m_data->selected_sprite->rotation);
	draw_str(buf, game->font[FS_20], tmp_str, pos);
	pos.x += 70;
	free(tmp_str);
	if (game->keyboard.key_pressed[BKS_R] && !m_data->any_menu_showed)
	{
		m_data->selected_sprite->rotation += ROT_90;
		if (m_data->selected_sprite->rotation > ROT_270)
			m_data->selected_sprite->rotation = ROT_0;
	}

	pos.x += draw_str(buf, game->font[FS_20], "MIRROR : M", pos);
	;
	tmp_str = generate_str("[%B]",
						   m_data->selected_sprite->mirror);
	draw_str(buf, game->font[FS_20], tmp_str, pos);
	pos.x += 100;
	free(tmp_str);
	if (game->keyboard.key_pressed[BKS_M] &&
		!m_data->any_menu_showed)
		m_data->selected_sprite->mirror =
			!m_data->selected_sprite->mirror;

	pos.x += draw_str(buf, game->font[FS_20], "MAP LAYER : L", pos);
	tmp_str = (m_data->map_layer) ? "[OVER]" : "[SUB]";
	draw_str(buf, game->font[FS_20], tmp_str, pos);
	pos.x += 80;
	if (game->keyboard.key_pressed[BKS_L])
	{
		sync_map_collisions(game->map, m_data->map_layer);
		m_data->map_layer = !m_data->map_layer;
	}

	pos.x += draw_str(buf, game->font[FS_20], "HIDE MAP : H", pos);
	tmp_str = generate_str("[%B]", m_data->hide_opposite_map);
	draw_str(buf, game->font[FS_20], tmp_str, pos);
	if (game->keyboard.key_pressed[BKS_H])
		m_data->hide_opposite_map = !m_data->hide_opposite_map;

	pos.x = buf->width - 300;
	draw_str(buf, game->font[FS_20], "DISPLAY COLLISIONS : SPACE", pos);
	if (game->keyboard.key_pressed[BKS_SPACE] && !m_data->any_menu_showed)
		m_data->show_collision = !m_data->show_collision;
}

void set_new_map(t_game *game,
				 t_editor_data *m_data)
{
	size_t i;
	size_t size;
	t_sprite_bank *bank;

	m_data->name = game->menu.editor_select_data.name;
	game->menu.editor_select_data.name = NULL;
	if (game->map == NULL)
	{
		game->map = new_map(game->menu.editor_select_data.map_size);
		game->map->map_asset = load_sprite_from_dir(MAP_ASSET_PATH);
		game->map->entity_array = new_entity_array();
	}
	else
	{
		bank = load_sprite_from_dir(MAP_ASSET_PATH);
		sprite_bank_append(game->map->map_asset, bank);
		bunny_free(bank);
	}
	size = sprite_bank_size(game->map->map_asset);
	m_data->tile_select = new_tile_array(SETPOS(size, 1));
	i = 0;
	while (i < size)
	{
		tile_add_layer(m_data->tile_select->tiles[i],
					   game->map->map_asset->sprites[i]);
		i++;
	}
}

void editor_menu(t_bunny_buffer *buf,
				 t_game *game)
{
	t_editor_data *m_data;
	t_entity entity;
	int entity_pos;

	m_data = &(game->menu.editor_data);
	if (game->menu.current != game->menu.previous)
	{
		init_editor_menu(game, m_data);
		set_new_map(game, m_data);
		m_data->entity = new_entity(NULL, SWORDSMAN, SETPOS(0, 0));
		update_entity_sprite(&m_data->entity, game->map->entities_asset);
		switch_music(&game->audio, game->audio.music[MU_EDITOR]);
		m_data->buttons[5].clicked_sound = game->audio.sfx[SFX_BACK1];
		m_data->buttons[6].clicked_sound = game->audio.sfx[SFX_BACK1];
		m_data->buttons[7].clicked_sound = game->audio.sfx[SFX_BACK1];
		game->menu.previous = game->menu.current;
	}
	m_data->any_menu_showed = CHECK_ANY_WINDOW_SHOWED(m_data);
	display_buttons(buf, game, m_data, m_data->any_menu_showed);
	m_data->any_menu_showed = CHECK_ANY_WINDOW_SHOWED(m_data);

	if (!m_data->any_menu_showed)
	{
		move_tile_camera(&game->map->camera,
						 &game->key_input, game->fps.delta_time);
	}
	if (!m_data->pause_window)
		play_map_animation(game->map);
	display_map(buf, game->map, m_data, NULL);
	if (m_data->add_entity_request)
	{
		find_entity(&game->map->entity_array, m_data->entity.pos, &entity_pos);
		if (entity_pos == -1)
		{
			entity = new_entity(NULL, m_data->entity.class,
								m_data->entity.pos);
			entity.team = m_data->entity.team;
			update_entity_sprite(&entity, game->map->entities_asset);
			add_entity(&game->map->entity_array, entity);
		}
		m_data->add_entity_request = false;
	}
	display_buttons(buf, game, m_data, m_data->any_menu_showed);

	display_down_bar(buf, game, m_data);
	if (m_data->pause_window)
		display_pause_window(buf, game, m_data);
	if (m_data->tile_window)
		display_tile_window(buf, game, m_data);
	if (m_data->side_window)
		display_side_window(buf, game, m_data);
	if (m_data->unit_window)
		display_unit_window(buf, game, m_data);
	draw_rect(buf, SETAREA(0, 0, buf->width, buf->height),
			  (m_data->map_layer) ? RED : BLUE);
}