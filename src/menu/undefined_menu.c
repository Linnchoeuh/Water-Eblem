/**
 ** @file undefined_menu.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "fe_menu.h"
#include "global.h"

void undefined_menu(t_bunny_buffer *buf,
					t_game *game)
{
	unsigned int original_color;

	if (game->menu.current != game->menu.previous)
		game->menu.previous = game->menu.current;

	original_color = game->font[FS_50]->color;
	game->font[FS_50]->color = RED;
	draw_str(buf, game->font[FS_50], "Undefined menu",
			 SETPOS(0, game->ws->buffer.height - FONT_SIZE[FS_50]));
	game->menu.current = M_MAIN;
	game->font[FS_50]->color = original_color;
}