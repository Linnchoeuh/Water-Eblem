/**
 ** @file play_menu.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "fe_menu.h"

static void button_play_menu(t_game *game,
							 t_play_data *m_data)
{
	t_button_data exit_button;
	t_button_data turn_button;
	t_bunny_position exit_pos;
	t_bunny_position turn_pos;

	exit_pos = SETPOS(130, 50);
	turn_pos = SETPOS(250, 50);
	exit_button = new_button(SETPOS(game->pic->buffer.width - 130, 0),
							 game->font[FS_50], WHITE, &exit_pos);
	turn_button = new_button(SETPOS(game->pic->buffer.width - 250, game->pic->buffer.height - 50),
							 game->font[FS_50], WHITE, &turn_pos);
	set_button_color_set(&exit_button, WHITE);
	set_button_color_set(&turn_button, WHITE);
	if (draw_button(&game->pic->buffer, &exit_button, game->mouse, "Exit") == true)
	{
		delete_map(game->map);
		game->map = NULL;
		game->menu.current = M_MAP_SELECT;
	}
	if (draw_button(&game->pic->buffer, &turn_button, game->mouse, "Next turn") == true)
	{
		if (game->menu.play_data.game_turn)
			game->menu.play_data.game_turn = 0;
		else
			game->menu.play_data.game_turn = 1;
		m_data->selected_entity = NULL;
		reset_movement_entity(&game->map->entity_array);
	}
}

void play_menu(t_bunny_buffer *buf,
			   t_game *game)
{
	t_play_data *m_data;
	t_range *range;

	m_data = &(game->menu.play_data);
	if (game->menu.current != game->menu.previous)
	{
		m_data->selected_entity = NULL;
		m_data->game_turn = 0;
		m_data->mouse = &game->mouse;
		switch_music(&game->audio, game->audio.music[MU_PLAY]);
		game->menu.previous = game->menu.current;
	}
	range = find_range(game->map->sub_part, &game->map->entity_array,
					   m_data->selected_entity, m_data->game_turn);
	move_tile_camera(&game->map->camera, &game->key_input,
					 game->fps.delta_time);
	play_map_animation(game->map);
	check_things(&game->map->entity_array);
	display_map(buf, game->map, NULL, m_data);
	display_range(buf, range, game->map->camera, m_data);
	button_play_menu(game, m_data);
	delete_range(range);
	if (game->keyboard.key_pressed[BKS_ESCAPE])
		m_data->selected_entity = NULL;
}