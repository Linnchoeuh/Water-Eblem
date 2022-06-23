/**
 ** @file find_range.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "range.h"

bool pos_exist(t_range *range,
			   t_bunny_position new_pos)
{
	size_t i;

	i = 0;
	while (i < range->nbr_pos)
	{
		if (range->pos[i].x == new_pos.x &&
			range->pos[i].y == new_pos.y)
			return (true);
		i++;
	}
	return (false);
}

void add_pos(t_range *range,
			 t_bunny_position new_pos)
{
	if (pos_exist(range, new_pos))
		return;
	range->nbr_pos += 1;
	range->pos = std_realloc(range->pos,
							 range->nbr_pos * sizeof(t_bunny_position));
	range->pos[range->nbr_pos - 1] = new_pos;
}

void tile_finder(t_range *range,
				 t_bunny_position pos,
				 int mvt,
				 bool start)
{
	t_tile *tile;
	bool is_block;
	bool ok;
	int entity_pos;

	if (mvt < 0)
		return;
	tile = find_tile(range->tile_array, pos);
	is_block = true;
	if (tile != NULL)
		is_block = tile->is_block;
	find_entity(range->entity_array, pos, &entity_pos);
	ok = (!is_block && entity_pos == -1);
	if (ok)
		add_pos(range, pos);
	if (ok || start)
	{
		pos.x += 1;
		tile_finder(range, pos, mvt - 1, false);
		pos.x -= 2;
		tile_finder(range, pos, mvt - 1, false);
		pos.x += 1;
		pos.y += 1;
		tile_finder(range, pos, mvt - 1, false);
		pos.y -= 2;
		tile_finder(range, pos, mvt - 1, false);
	}
}

t_range *find_range(t_tile_array *tile_array,
					t_entity_array *entity_array,
					t_entity *entity,
					int turn)
{
	t_range *range;
	t_entity tmp_entity;
	t_bunny_position pos;
	int entity_pos;


	if (entity == NULL)
		return (NULL);
	range = bunny_malloc(sizeof(t_range));
	range->nbr_pos = 0;
	range->entity_array = entity_array;
	range->tile_array = tile_array;
	range->pos = bunny_malloc(0);
	pos = entity->pos;
	tile_finder(range, entity->pos, entity->max_movement, true);
	pos.x += 1;
	tmp_entity = find_entity(entity_array,
							pos,
							&entity_pos);
	range->right = 0;
	if (entity_pos > 0)
		range->right = 1 + (tmp_entity.team == turn);

	pos.x -= 2;
	tmp_entity = find_entity(entity_array, pos, &entity_pos);
	range->left = 0;
	if (entity_pos > 0)
		range->left = 1 + (tmp_entity.team == turn);

	pos.x += 1;
	pos.y += 1;
	tmp_entity = find_entity(entity_array, pos, &entity_pos);
	range->down = 0;
	if (entity_pos > 0)
		range->down = 1 + (tmp_entity.team == turn);

	pos.y -= 2;
	tmp_entity = find_entity(entity_array, pos, &entity_pos);
	range->up = 0;
	if (entity_pos > 0)
		range->up = 1 + (tmp_entity.team == turn);

	return (range);
}