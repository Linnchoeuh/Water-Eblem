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
	if (action_type == 1 && current->attacked == 0)
	{
		combat(current, target);
		current->attacked = 1;
	}
	if (action_type == 2 && current->attacked == 0)
	{
		healing(current, target);
		current->attacked = 1;
	}
}

void entity_mover(t_bunny_buffer *buf,
				  t_bunny_position pos,
				  t_bunny_area area,
				  t_play_data *m_data)
{
	bool touched;

	if (mouse_button(area, *(m_data->mouse), BMB_LEFT, &touched))
	{
		m_data->prev_pos = m_data->selected_entity->pos;
		m_data->selected_entity->pos = pos;
		m_data->selected_entity->played = true;
	}
	if (touched)
	{
		draw_rect(buf, area, PURPLE);
	}
}

void display_range(t_bunny_buffer *buf,
				   t_range *range,
				   t_tile_camera cam,
				   t_play_data *m_data)
{
	unsigned int i;
	t_bunny_area area;
	t_bunny_position size;
	t_bunny_position offset;
	t_entity tmp_entity;
	unsigned int colors[3];

	colors[0] = COLOR(0, 0, 0, 0);
	colors[1] = COLOR(64, 255, 64, 64);
	colors[2] = COLOR(64, 64, 255, 64);

	if (range == NULL)
		return;
	i = 0;
	size.x = SQUARE_SIZE * cam.zoom;
	size.y = SQUARE_SIZE * cam.zoom;
	offset.x = buf->width / 2 - size.x / 2;
	offset.y = buf->height / 2 - size.y / 2;
	area.w = SQUARE_SIZE * cam.zoom;
	area.h = SQUARE_SIZE * cam.zoom;
	while (i < range->nbr_pos)
	{
		area.x = (range->pos[i].x - cam.tile_pos.x) * size.x + offset.x;
		area.y = (range->pos[i].y - cam.tile_pos.y) * size.y + offset.y;
		draw_full_rect(buf, area, COLOR(64, 64, 64, 255));
		if (m_data != NULL && m_data->selected_entity->played == false)
			entity_mover(buf, range->pos[i], area, m_data);
		++i;
	}
	area.x = (m_data->selected_entity->pos.x - cam.tile_pos.x) * size.x + offset.x;
	area.y = (m_data->selected_entity->pos.y - cam.tile_pos.y - 1) * size.y + offset.y;
	draw_full_rect(buf, area, colors[range->up]);
	tmp_entity = find_entity(range->entity_array,
							 SETPOS(m_data->selected_entity->pos.x,
									m_data->selected_entity->pos.y), NULL);
	if (mouse_button(area, *(m_data->mouse), BMB_LEFT, NULL))
		launch_action(m_data->selected_entity, &tmp_entity, range->up);

	area.x = (m_data->selected_entity->pos.x - cam.tile_pos.x) * size.x + offset.x;
	area.y = (m_data->selected_entity->pos.y - cam.tile_pos.y + 1) * size.y + offset.y;
	draw_full_rect(buf, area, colors[range->down]);
	tmp_entity = find_entity(range->entity_array,
							 SETPOS(m_data->selected_entity->pos.x,
									m_data->selected_entity->pos.y + 1), NULL);
	if (mouse_button(area, *(m_data->mouse), BMB_LEFT, NULL))
		launch_action(m_data->selected_entity, &tmp_entity, range->down);

	area.x = (m_data->selected_entity->pos.x - cam.tile_pos.x - 1) * size.x + offset.x;
	area.y = (m_data->selected_entity->pos.y - cam.tile_pos.y) * size.y + offset.y;
	draw_full_rect(buf, area, colors[range->left]);
	tmp_entity = find_entity(range->entity_array,
							 SETPOS(m_data->selected_entity->pos.x - 1,
									m_data->selected_entity->pos.y), NULL);
	if (mouse_button(area, *(m_data->mouse), BMB_LEFT, NULL))
		launch_action(m_data->selected_entity, &tmp_entity, range->left);

	area.x = (m_data->selected_entity->pos.x - cam.tile_pos.x + 1) * size.x + offset.x;
	area.y = (m_data->selected_entity->pos.y - cam.tile_pos.y) * size.y + offset.y;
	draw_full_rect(buf, area, colors[range->right]);
	tmp_entity = find_entity(range->entity_array,
							 SETPOS(m_data->selected_entity->pos.x,
									m_data->selected_entity->pos.y - 1), NULL);
	if (mouse_button(area, *(m_data->mouse), BMB_LEFT, NULL))
		launch_action(m_data->selected_entity, &tmp_entity, range->right);
}