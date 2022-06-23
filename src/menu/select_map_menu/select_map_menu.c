/**
 ** @file map_menu.c
 ** @author Ethan Nguyen
 ** @brief
 **/

#include "fe_menu.h"

void select_map_menu(t_bunny_buffer *buf,
                     t_game *game)
{
    size_t i;
    t_select_map_data *m_data;
    t_button_data *button;

    m_data = &(game->menu.select_map_data);
    if (game->menu.current != game->menu.previous)
    {
        if (game->map_list == NULL)
            game->map_list = create_map_list(MAP_PATH);
        switch_music(&game->audio, game->audio.music[MU_MAIN]);
        i = 0;
        while (i < NBR_BUTTON_MAP_SELECT_MENU)
        {
            button = &m_data->buttons[i];
            (*button) = new_button(SETPOS(0, 0),
                                   game->font[FS_50], WHITE, NULL);
            button->touched_sound = game->audio.sfx[SFX_MAP_MOVE];
            button->clicked_sound = game->audio.sfx[SFX_VALIDATE];
            i++;
        }
        game->menu.previous = game->menu.current;
    }
    m_data->buttons[0].pos = SETPOS(10, 10);
    m_data->buttons[0].clicked_sound = game->audio.sfx[SFX_BACK1];
    if (display_map_list(buf, game->map_list, game, 70))
    {
        delete_map_list(game->map_list);
        game->map_list = NULL;
        game->menu.current = M_GAME;
    }
    if (draw_button(buf, &m_data->buttons[0], game->mouse, "BACK"))
    {
        delete_map_list(game->map_list);
        game->map_list = NULL;
        game->menu.current = M_MAIN;
    }
}