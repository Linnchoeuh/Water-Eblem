/**
 ** @file display_range.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "range.h"

#define SQUARE_SIZE 16

void launch_action(t_entity *current,
				   t_entity *target,
				   int action_type)
{
	if (action_type == TILE_ATTACK && current->attacked == 0 &&
		current->team != target->team)
	{
		combat(current, target);
		current->attacked = 1;
	}
	if (action_type == TILE_HEAL && current->attacked == 0 &&
		current->team == target->team)
	{
		healing(current, target);
		current->attacked = 1;
	}
}

void display_range(t_bunny_buffer *buf,
				   t_range *range,
				   t_tile_camera cam,
				   t_play_data *m_data)
{
	int entity_pos;
	unsigned int i;
	unsigned int colors[NBR_TILE_TYPE];
	t_bunny_area area;
	t_bunny_position size;
	t_bunny_position offset;
	t_entity tmp_entity;

	if (range == NULL)
		return;
	colors[TILE_NOTHING] = COLOR(0, 0, 0, 0);
	colors[TILE_NONE] = COLOR(64, 64, 64, 255);
	colors[TILE_ALLY] = colors[TILE_NONE];
	colors[TILE_ENEMY] = COLOR(128, 255, 64, 64);
	colors[TILE_ATTACK] = colors[TILE_ENEMY];
	colors[TILE_ALLY_HEAL] = COLOR(64, 64, 255, 64);
	colors[TILE_HEAL] = colors[TILE_ALLY_HEAL];
	i = 0;
	size.x = SQUARE_SIZE * cam.zoom;
	size.y = SQUARE_SIZE * cam.zoom;
	offset.x = buf->width / 2 - size.x / 2;
	offset.y = buf->height / 2 - size.y / 2;
	area.w = SQUARE_SIZE * cam.zoom;
	area.h = SQUARE_SIZE * cam.zoom;
	while (i < range->nbr_pos)
	{
		area.x = (range->data[i].pos.x - cam.tile_pos.x) * size.x + offset.x;
		area.y = (range->data[i].pos.y - cam.tile_pos.y) * size.y + offset.y;
		draw_full_rect(buf, area, colors[range->data[i].type]);
		if (m_data != NULL)
		{
			if (IS_POINT_IN_AREA(area, m_data->mouse->pos))
				draw_rect(buf, area, PURPLE);
			if (mouse_button(area, *(m_data->mouse), BMB_LEFT, NULL))
			{
				tmp_entity = find_entity(range->entity_array,
										 range->data[i].pos, &entity_pos);
				if (range->data[i].type == TILE_NONE &&
					!m_data->selected_entity->moved)
				{
					m_data->prev_pos = m_data->selected_entity->pos;
					m_data->selected_entity->pos = range->data[i].pos;
					m_data->selected_entity->moved = true;
				}
				else if (range->data[i].type != TILE_NONE && entity_pos != -1)
					launch_action(range->entity, &tmp_entity, range->data[i].type);
			}
		}
		++i;
	}
}