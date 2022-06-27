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
		if (SAMEPOS(range->data[i].pos, new_pos))
			return (true);
		i++;
	}
	return (false);
}

bool add_pos(t_range *range,
			 t_bunny_position new_pos,
			 int type)
{
	if (pos_exist(range, new_pos))
		return (false);
	range->nbr_pos += 1;
	range->data = std_realloc(range->data,
							  range->nbr_pos * sizeof(t_range_data));
	if (range->data == NULL)
	{
		range->nbr_pos = 0;
		return (false);
	}
	range->data[range->nbr_pos - 1].pos = new_pos;
	range->data[range->nbr_pos - 1].type = type;
	return (true);
}

void tile_finder(t_range *range,
				 t_bunny_position pos,
				 int mvt)
{
	int type;
	int entity_pos;
	bool ok;
	bool is_block;
	t_tile *tile;
	t_entity tmp_entity;

	if (mvt < 0)
		return;
	ok = true;
	if (!SAMEPOS(range->entity->pos, pos))
	{
		tile = find_tile(range->tile_array, pos);
		tmp_entity = find_entity(range->entity_array, pos, &entity_pos);
		type = TILE_NONE;
		is_block = ((tile != NULL) ? tile->is_block : true);
		ok = !is_block;
		if (!is_block && entity_pos != -1)
		{
			if (tmp_entity.team == range->entity->team)
			{
				type = TILE_ALLY;
				if (range->entity->equiped->type == HEAL_STAFF)
					type = TILE_ALLY_HEAL;
			}
			else
			{
				type = TILE_ENEMY;
				ok = false;
			}
		}
		if (!is_block)
			add_pos(range, pos, type);
	}
	if (ok)
	{
		pos.x += 1;
		tile_finder(range, pos, mvt - 1);
		pos.x -= 2;
		tile_finder(range, pos, mvt - 1);
		pos.x += 1;
		pos.y += 1;
		tile_finder(range, pos, mvt - 1);
		pos.y -= 2;
		tile_finder(range, pos, mvt - 1);
	}
}

void weapon_range_finder(t_range *range,
						 t_bunny_position pos,
						 int *weapon_range,
						 int current_range)
{
	int type;

	if (current_range > weapon_range[MAX_RANGE] ||
		find_tile(range->tile_array, pos) == NULL)
		return;
	type = TILE_NOTHING;
	if (current_range >= weapon_range[MIN_RANGE])
	{
		type = TILE_ATTACK;
		if (range->entity->equiped->type == HEAL_STAFF)
			type = TILE_HEAL;
	}
		add_pos(range, pos, type);
	pos.x += 1;
	weapon_range_finder(range, pos, weapon_range, current_range + 1);
	pos.x -= 2;
	weapon_range_finder(range, pos, weapon_range, current_range + 1);
	pos.x += 1;
	pos.y += 1;
	weapon_range_finder(range, pos, weapon_range, current_range + 1);
	pos.y -= 2;
	weapon_range_finder(range, pos, weapon_range, current_range + 1);
}

t_range *find_range(t_tile_array *tile_array,
					t_entity_array *entity_array,
					t_entity *entity,
					int turn)
{
	t_range *range;

	if (entity == NULL || turn != entity->team)
		return (NULL);
	range = bunny_malloc(sizeof(t_range));
	if (range == NULL)
		return (NULL);
	range->data = bunny_malloc(0);
	if (range->data == NULL)
	{
		delete_range(range);
		return (NULL);
	}
	range->nbr_pos = 0;
	range->entity = entity;
	range->tile_array = tile_array;
	range->entity_array = entity_array;
	if (!entity->attacked)
	{
		if (!entity->moved)
			tile_finder(range, entity->pos, entity->max_movement);
		else if (entity->equiped != NULL)
			weapon_range_finder(range, entity->pos, entity->equiped->range, 0);
	}
	return (range);
}