/**
 ** @file display_map_list.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "map.h"

bool display_map_list(t_bunny_buffer *buf,
					  t_map_list *map_list,
					  t_game *game,
					  int init_y_pos)
{
	bool clicked;
	size_t i;
	char *tmp_str;
	t_button_data button;
	t_bunny_position rect_size;

	if (map_list == NULL)
		return (false);
	i = 0;
	rect_size = SETPOS(buf->width - 100, 90);
	button = new_button(SETPOS(50, init_y_pos), game->font[FS_50],
						WHITE, &rect_size);
	button.clicked_sound = game->audio.sfx[SFX_VALIDATE];
	clicked = false;
	button.disable_button = map_list->disable_buttons;
	map_list->taken_name = NULL;
	while (map_list->elem[i] != NULL)
	{
		if (draw_button(buf, &button, game->mouse,
						map_list->elem[i]->name))
		{
			map_list->taken_name = map_list->elem[i]->name;
			if (game->map != NULL)
				delete_map(game->map);
			tmp_str = generate_str("%s.map", map_list->elem[i]->name);
			game->map = load_map(map_list->elem[i]->full_path,
								 tmp_str);
			bunny_free(tmp_str);
			clicked = (game->map != NULL);
		}
		tmp_str = generate_str("Map size : [%d, %d]",
							   map_list->elem[i]->map_size.x,
							   map_list->elem[i]->map_size.y);
		draw_str(buf, game->font[FS_20], tmp_str,
				 SETPOS(button.pos.x + 20, button.pos.y + 60));
		bunny_free(tmp_str);
		button.pos.y += 120;
		i++;
	}
	return (clicked);
}