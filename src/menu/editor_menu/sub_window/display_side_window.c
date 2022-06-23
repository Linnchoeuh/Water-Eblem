/**
 ** @file display_side_window.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "fe_menu.h"

static void display_side_window_background(t_bunny_buffer *buf)
{
	t_bunny_area area;

	area = SETAREA(0, 0, buf->width, buf->height);
	draw_full_rect(buf, area, COLOR(128, 0, 0, 0));
	area = SETAREA(buf->width - 450, 0, 450, buf->height);
	draw_full_rect(buf, area, BLACK);
	draw_rect(buf, area, WHITE);
}

void display_side_back_button(t_bunny_buffer *buf,
							  t_button_data *button,
							  t_game *game,
							  t_editor_data *m_data)
{
	button->pos = SETPOS(buf->width - 110, 0);
	if (draw_button(buf, button, game->mouse, "BACK") ||
		game->keyboard.key_pressed[BKS_ESCAPE])
	{
		game->keyboard.key_pressed[BKS_ESCAPE] = false;
		game->map->camera.zoom = m_data->zoom;
		m_data->side_window = false;
	}
}

void display_layer_list(t_bunny_buffer *buf,
						t_tile *tile,
						t_button_data *button,
						t_editor_data *m_data)
{
	size_t i;

	button->touched_sound = NULL;
	set_button_color_set(button, RED);
	i = 0;
	while (i < count_tile_layers(tile))
	{
		button->pos = SETPOS(buf->width - 440, (i + 2) * 60);
		display_animation(buf, tile->layers[i],
						  SETAREA(buf->width - 340, button->pos.y + 5, 40, 40));
		if (draw_button(buf, button, *(m_data->mouse), "[X]"))
			remove_tile_layer(tile, i);
		i++;
	}
}

void display_side_window_entity(t_bunny_buffer *buf,
								t_button_data *button,
								t_editor_data *m_data,
								t_game *game)
{
	int entity_pos;
	t_entity entity;
	t_bunny_position pos;


	pos = SETPOS(buf->width - 440, 60);
	draw_str(buf, button->font, "ENTITY", pos);
	pos = SETPOS(buf->width - 250, 60);
	entity = find_entity(&game->map->entity_array,
						 m_data->tile_pos, &entity_pos);
	if (entity_pos == -1)
		draw_str(buf, button->font, "NONE", pos);
	else
	{
		display_entity(buf, &entity, SETAREA(buf->width - 150, 60, 50, 50));
		set_button_color_set(button, RED);
		button->pos = pos;
		if (draw_button(buf, button, *(m_data->mouse), "[X]"))
			remove_entity(&game->map->entity_array, entity_pos);
	}
}

void display_side_clear_button(t_bunny_buffer *buf,
							   t_tile *tile,
							   t_button_data *button,
							   t_editor_data *m_data)
{

	set_button_color_set(button, RED);
	button->pos = SETPOS(buf->width - 440, buf->height - 50);
	if (draw_button(buf, button, *m_data->mouse, "CLEAR TILE LAYER"))
		clear_tile_layers(tile);
}

void display_side_window(t_bunny_buffer *buf,
						 t_game *game,
						 t_editor_data *m_data)
{
	t_tile *tile;

	if (m_data->map_layer)
		tile = game->map->over_part->tiles[m_data->pos_1d];
	else
		tile = game->map->sub_part->tiles[m_data->pos_1d];
	game->map->camera.tile_pos = SETPOS_ACC(m_data->tile_pos.x + 1.5,
											m_data->tile_pos.y);
	game->map->camera.zoom = m_data->zoom_max;
	display_side_window_background(buf);
	display_side_back_button(buf, &m_data->buttons[7], game, m_data);
	display_side_window_entity(buf, &m_data->buttons[16], m_data, game);
	display_layer_list(buf, tile, &m_data->buttons[8], m_data);
	m_data->buttons[9].font = game->font[FS_40];
	display_side_clear_button(buf, tile, &m_data->buttons[9], m_data);
}