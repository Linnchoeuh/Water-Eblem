/**
 ** @file read_map_bin_entity.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "map.h"

static bool read_other_item(int32_t item_type,
							t_inventory *inventory)
{
	if (item_type == POTION)
		add_obj_inventory(inventory, create_object(POTION, 0));
	return (true);
}

static bool read_weapon(int fd,
						t_inventory *inventory)
{
	ssize_t tmp_size;
	int32_t tier;
	int32_t type;

	tmp_size = sizeof(int32_t);
	if (read(fd, &type, tmp_size) != tmp_size)
		return (false);
	if (read(fd, &tier, tmp_size) != tmp_size)
		return (false);
	add_obj_inventory(inventory, create_object(type, tier));
	return (true);
}

static bool read_entity_inventory(int fd,
								  t_inventory *inventory)
{
	bool success;
	int i;
	ssize_t tmp_size;
	int32_t type;

	i = 0;
	tmp_size = sizeof(int32_t);
	if (read(fd, &inventory->max_size, tmp_size) != tmp_size)
		return (false);
	success = true;
	inventory->objs = bunny_malloc(inventory->max_size * sizeof(t_obj));
	while (i < inventory->max_size)
	{
		if (read(fd, &type, tmp_size) != tmp_size)
			return (false);
		if (type <= NBR_WEAPONS && type != NO_ITEM)
			success = read_weapon(fd, inventory);
		else if (type == POTION)
			success = read_other_item(POTION, inventory);
		if (!success)
			return (false);
		i++;
	}
	return (true);
}

bool read_map_bin_entity(int fd,
						 t_map *map)
{
	int i;
	ssize_t tmp_size;
	int32_t tmp_val;
	int32_t nbr_entities;
	int32_t equiped_weapon;
	t_entity entity;
	t_bunny_position pos;

	tmp_size = sizeof(int32_t);
	if (read(fd, &nbr_entities, tmp_size) != tmp_size)
		return (false);
	i = 0;
	while (i < nbr_entities)
	{
		printo("\rMAP LOADER: Loading entity %d/%d",
			   i + 1, nbr_entities);
		tmp_size = sizeof(int32_t);
		if (read(fd, &tmp_val, tmp_size) != tmp_size)
			return (false);
		tmp_size = sizeof(t_bunny_position);
		if (read(fd, &pos, tmp_size) != tmp_size)
			return (false);
		entity = new_entity(NULL, tmp_val, pos);
		tmp_size = sizeof(int32_t);
		if (read(fd, &entity.team, tmp_size) != tmp_size)
			return (false);
		free_inventory(&entity.inventory);
		if (!read_entity_inventory(fd, &entity.inventory))
			return (false);
		if (read(fd, &equiped_weapon, tmp_size) != tmp_size)
			return (false);
		entity.equiped = NULL;
		if (equiped_weapon != -1)
			entity.equiped =
				entity.inventory.objs[equiped_weapon].content;
		update_entity_sprite(&entity, map->entities_asset);
		add_entity(&map->entity_array, entity);
		i++;
	}
	printo("\n");
	return (true);
}