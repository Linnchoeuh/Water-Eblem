/**
 ** @file display_entity_array.h
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "map_struct.h"
#include "bunny_macro.h"
#include "entities.h"

#define TILE_SIZE 16

void entity_selector(t_bunny_buffer *buf,
                     t_entity *entity,
                     t_bunny_area area,
                     t_play_data *m_data)
{
    bool touched;


    if (mouse_button(area, *(m_data->mouse), BMB_LEFT, &touched) &&
        entity->team == m_data->game_turn && m_data->selected_entity == NULL)
	{
		m_data->selected_entity = entity;
	}
	if (touched)
	{
		draw_rect(buf, area, WHITE);
	}
}

void display_entity_array(t_bunny_buffer *buf,
                          t_entity_array *entity_array,
                          t_tile_camera cam,
                          t_play_data *m_data)
{
    int i;
    t_entity *entity;
    t_bunny_area area;
    t_bunny_position size;
    t_bunny_position offset;

    i = 0;
    size.x = TILE_SIZE * cam.zoom;
    size.y = TILE_SIZE * cam.zoom;
    offset.x = buf->width / 2 - size.x / 2;
	offset.y = buf->height / 2 - size.y / 2;
    area.w = TILE_SIZE * cam.zoom;
    area.h = TILE_SIZE * cam.zoom;
    while (i < entity_array->nbr_entities)
    {
        entity = &entity_array->entities[i];
        area.x = (entity->pos.x - cam.tile_pos.x) * size.x + offset.x;
        area.y = (entity->pos.y - cam.tile_pos.y) * size.y + offset.y;
        display_entity(buf, entity, area);
        if (m_data != NULL)
            entity_selector(buf, entity, area, m_data);
        ++i;
    }
}

