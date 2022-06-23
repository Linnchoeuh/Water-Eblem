/**
 ** @file game_struct_setup.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "game.h"
#include "global.h"

#define TEXT "Je suis un test mon existence, \
ne se resume qu'a une veille fenetre \
qui sera supprime dans deux commit, \
mais au moins on voit que ca fonctionne. \
Mais vu qu'il faut faire du remplissage \
je vais prolonger un peu se test pour que ca aille jusqu'en bas. \
Faites que j'ai ecrit assez. Ben en fait c'etait pas assez \
donc c'est reparti pour plus de texte encore... \
PUTAIN C'EST TOUJOURS PAS SUFFISANT ALLER LA VIE DE MA MERE."

static void setup_audio_struct(t_audio *audio)
{
	audio->music_vol = 100;
	audio->sfx_vol = 100;
	audio->master_vol = 100;
	audio->played_music = NULL;
	audio->music = load_audio_from_dir(MUSIC_PATH, &audio->nbr_music, true);
	audio->sfx = load_audio_from_dir(SFX_PATH, &audio->nbr_sfx, false);
}

static void load_fonts(t_bunny_font **fonts)
{
	size_t i;
	t_bunny_position pos;

	i = 0;
	while (i < FS_TOTAL)
	{
		pos = SETPOS(0, FONT_SIZE[i]);
		fonts[i] = bunny_load_font(4096, pos.y, FONT_PATH, &pos);
		fonts[i]->clipable.smooth = true;
		fonts[i]->clipable.mosaic = false;
		fonts[i]->offset.y -= fonts[i]->glyph_size.y / 5;
		i++;
	}
}

#include "dialog.h"

t_game *game_struct_setup(int width,
						  int height,
						  unsigned int max_fps)
{
	t_game *game;

	game = bunny_malloc(sizeof(t_game));
	if (game == NULL)
		return (NULL);
	game->ws = NULL;
	game->pic = NULL;
	game->quit = false;
	game->ws = bunny_start(width, height, false, "Fire Emblem");
	game->pic = bunny_new_picture(width, height);
	load_fonts(game->font);
	if (game->ws == NULL || game->pic == NULL)
	{
		game_struct_delete(game);
		return (NULL);
	}
	game->map = NULL;
	game->menu.current = M_MAIN;
	game->map_list = NULL;
	game->menu.previous = -1;
	mouse_init_struct(&game->mouse);
	keyboard_init_struct(&game->keyboard);
	framerate_init_struct(&game->fps, max_fps);
	setup_audio_struct(&game->audio);
	init_editor_menu(game, &game->menu.editor_data);
	game->conv = new_conv();
	add_dialog(game->conv, new_dialog("un", game->font[FS_30], NULL, NULL));
	add_dialog(game->conv, new_dialog("deux", game->font[FS_30], NULL, NULL));
	add_dialog(game->conv, new_dialog("trois", game->font[FS_30], NULL, NULL));
	add_dialog(game->conv, new_dialog("quatre", game->font[FS_30], NULL, NULL));
	return (game);
}