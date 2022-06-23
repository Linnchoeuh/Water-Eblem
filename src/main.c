/**
 ** @file main.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "fe.h"
#include "global.h"
#include "path.h"

static t_bunny_response	mouse_event_response(t_bunny_event_state state,
					    					 t_bunny_mouse_button clic_code,
					    					 void *data)
{
	size_t i;
  	t_game *game;
	const bool *buttons;

	(void)state;
	(void)clic_code;
	game = (t_game*) data;
	buttons = bunny_get_mouse_button();

	i = 0;
	while (i < LAST_BUNNY_MOUSEBUTTON)
	{
		game->mouse.button[i] = buttons[i];
		i++;
	}
	return(GO_ON);
}

static t_bunny_response	key_response(t_bunny_event_state state,
									 t_bunny_keysym	sym,
									 void *data)
{
	const bool *keys;
	t_game *game;
	int i;

	(void)sym;
	(void)state;
	game = data;
	keys = bunny_get_keyboard();
	i = 0;
	while (i < BKS_LAST_KEY)
	{
		game->keyboard.key[i] = keys[i];
		i++;
	}
	if (keys[BKS_LSHIFT] && keys[BKS_ESCAPE])
		return (EXIT_ON_SUCCESS);
	return (GO_ON);
}

t_bunny_response mainloop(void *data)
{
	t_game *game;

	game = data;
	game->mouse.pos = *bunny_get_mouse_position();
	set_key_input(&game->key_input, &game->keyboard);

	// bunny_clear(&game->pic->buffer, COLOR(255, 0, 0, 0));
	bunny_fill(&game->pic->buffer, BLACK);

	MENUS[game->menu.current](&game->pic->buffer, game);
	bunny_blit(&game->ws->buffer, game->pic, NULL);
	//framerate_display_fps(&game->ws->buffer, game->font[FS_15], game->fps);
	bunny_display(game->ws);
	update_framerate_data(&game->fps);
	// framerate_log_fps(game->fps, 0);
	mouse_check_button_pressed(&game->mouse);
	keyboard_check_button_pressed(&game->keyboard);
	reset_key_input(&game->key_input);
	// printo("%c", interpret_keyboard(game->keyboard.key, game->keyboard.key_pressed));

	return ((game->quit) ? EXIT_ON_SUCCESS : GO_ON);
}

int	main(void)
{
	t_game *game;

	game = game_struct_setup(1280, 720, 60);
	if (game == NULL)
		return (1);
	bunny_set_key_response(key_response);
	bunny_set_loop_main_function(mainloop);
	bunny_set_click_response(mouse_event_response);
	bunny_loop(game->ws, game->fps.max, game);
	game_struct_delete(game);
	return (0);
}