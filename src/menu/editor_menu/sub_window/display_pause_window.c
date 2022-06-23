/**
 ** @file display_pause_window.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "fe_menu.h"

static void display_pause_window_background(t_bunny_buffer *buf,
											t_bunny_font *font)
{
	t_bunny_area area;

	area = SETAREA(0, 0, buf->width, buf->height);
	draw_full_rect(buf, area, COLOR(128, 0, 0, 0));
	area = SETAREA(buf->width / 2 - 175, 50, 350, 500);
	draw_full_rect(buf, area, BLACK);
	draw_rect(buf, area, WHITE);
	draw_str(buf, font, "PAUSE", SETPOS(buf->width / 2 - 160, 60));
}

static void pause_menu_resume_button(t_bunny_buffer *buf,
									 t_button_data *button,
									 t_editor_data *m_data,
									 t_game *game)
{
	button->pos = SETPOS(buf->width / 2, 300);
	button->center_rect = true;
	if (draw_button(buf, button, game->mouse, "RESUME") ||
		game->keyboard.key_pressed[BKS_ESCAPE])
	{
		game->keyboard.key_pressed[BKS_ESCAPE] = false;
		m_data->pause_window = false;
	}
}

static void pause_menu_save_button(t_bunny_buffer *buf,
								   t_button_data *button,
								   t_editor_data *m_data,
								   t_game *game)
{

	button->pos = SETPOS(buf->width / 2, 400);
	button->center_rect = true;
	if (draw_button(buf, button, game->mouse, "SAVE"))
		save_map(game->map, MAP_PATH, m_data->name);
}

static void pause_menu_quit_button(t_bunny_buffer *buf,
								   t_button_data *button,
								   t_editor_data *m_data,
								   t_game *game)
{

	button->pos = SETPOS(buf->width / 2, 500);
	button->center_rect = true;
	set_button_color_set(button, RED);
	if (draw_button(buf, button, game->mouse, "BACK TO MENU"))
	{
		delete_map(game->map);
		game->map = NULL;
		delete_editor_menu_content(m_data);
		game->menu.current = M_EDITOR_SELECT;
	}
}

void display_pause_window(t_bunny_buffer *buf,
						  t_game *game,
						  t_editor_data *m_data)
{
	display_pause_window_background(buf, game->font[FS_100]);
	pause_menu_resume_button(buf, &m_data->buttons[3], m_data, game);
	pause_menu_save_button(buf, &m_data->buttons[4], m_data, game);
	pause_menu_quit_button(buf, &m_data->buttons[5], m_data, game);
}