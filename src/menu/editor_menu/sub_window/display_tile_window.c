/**
 ** @file tile_window.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "fe_menu.h"

#define TILE_SPACE 48
#define TILE_X_START 16
#define TILE_Y_START 66
#define TILE_SELECT_SIZE SETPOS(32, 32)

bool display_tile_back_button(t_bunny_buffer *buf,
							  t_button_data *button,
							  t_keyboard *keyboard,
							  t_mouse *mouse)
{
	t_bunny_area area;

	area = SETAREA(0, 0, buf->width, buf->height);
	draw_full_rect(buf, area, COLOR(220, 32, 32, 32));
	button->pos = SETPOS(buf->width - 110, 0);
	if (draw_button(buf, button, *mouse, "BACK") ||
		keyboard->key_pressed[BKS_ESCAPE])
	{
		keyboard->key_pressed[BKS_ESCAPE] = false;
		return (false);
	}
	return (true);
}

bool tile_select_button(t_editor_data *m_data,
						t_bunny_area tile_area,
						t_mouse *mouse,
						t_tile *tile)
{
	bool touched;

	if (mouse_button(tile_area, *mouse, BMB_LEFT, &touched))
	{
		m_data->tile_window = false;
		m_data->block_placing = false;
		change_animation_sprite(m_data->selected_sprite,
			tile->layers[0]->sprite);
	}
	return (touched);
}

void play_audio_tile_select_button(t_bunny_music *sfx,
								   bool *any_tile_button_touched,
								   bool *any_touch)
{
	(*any_touch) = true;
	if (!(*any_tile_button_touched))
	{
		bunny_sound_set_cursor(&sfx->sound, 0);
		bunny_sound_play(&sfx->sound);
	}
}

void display_tile_select(t_bunny_buffer *buf,
						 t_game *game,
						 t_editor_data *m_data)
{
	bool any_touch;
	size_t i;
	size_t nb_tiles;
	t_tile *tile;
	t_bunny_area tile_area;

	i = 0;
	any_touch = false;
	nb_tiles = buf->width / TILE_SPACE;
	play_tile_array(m_data->tile_select, bunny_get_time());
	while (game->map->map_asset->sprites[i] != NULL)
	{
		tile_area = SETAREA(
			TILE_X_START + TILE_SPACE * (i % nb_tiles),
			TILE_Y_START + TILE_SPACE * (i / nb_tiles),
			TILE_SELECT_SIZE.x, TILE_SELECT_SIZE.y);
		tile = m_data->tile_select->tiles[i];
		display_tile(buf, tile, tile_area);
		if (tile_select_button(m_data, tile_area, &game->mouse, tile))
		{
			play_audio_tile_select_button(game->audio.sfx[SFX_MAP_MOVE],
				&m_data->any_tile_button_touched, &any_touch);
			draw_rect(buf, tile_area, YELLOW);
		}
		i++;
	}
	m_data->any_tile_button_touched = any_touch;
}

void display_tile_window(t_bunny_buffer *buf,
						 t_game *game,
						 t_editor_data *m_data)
{
	m_data->tile_window = display_tile_back_button(
		buf, &m_data->buttons[6], &game->keyboard, &game->mouse);
	display_tile_select(buf, game, m_data);
}