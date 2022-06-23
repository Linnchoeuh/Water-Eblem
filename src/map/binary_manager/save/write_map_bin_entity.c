/**
 ** @file write_map_bin_entity.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "map.h"

static int32_t find_equiped_weapon(t_weapon *equiped_weapon,
								   t_inventory *inventory)
{
	int32_t i;

	if (equiped_weapon == NULL)
		return (-1);
	i = 0;
	while (i < inventory->nbr_obj)
	{
		if (equiped_weapon == inventory->objs[i].content)
			return (i);
		i++;
	}
	return (-1);
}

static bool write_other_item(int fd,
							 int32_t item_type)
{
	ssize_t tmp_size;

	tmp_size = sizeof(int32_t);
	return (write(fd, &item_type, tmp_size) == tmp_size);
}

static bool write_weapon(int fd,
						 t_weapon *weapon)
{
	ssize_t tmp_size;
	int32_t item_type;

	item_type = NBR_WEAPONS;
	tmp_size = sizeof(int32_t);
	if (write(fd, &item_type, tmp_size) != tmp_size)
		return (false);
	if (write(fd, &weapon->type, tmp_size) != tmp_size)
		return (false);
	if (write(fd, &weapon->tier, tmp_size) != tmp_size)
		return (false);
	return (true);
}

static bool write_entity_inventory(int fd,
								   t_inventory *inventory)
{
	bool success;
	int i;
	ssize_t tmp_size;

	i = 0;
	tmp_size = sizeof(int32_t);
	if (write(fd, &inventory->max_size, tmp_size) != tmp_size)
		return (false);
	success = true;
	while (i < inventory->max_size)
	{
		if (i < inventory->nbr_obj)
		{
			if (inventory->objs[i].type <= NBR_WEAPONS)
				success = write_weapon(fd, inventory->objs[i].content);
			else if (inventory->objs[i].type == POTION)
				success = write_other_item(fd, POTION);
			else
				success = write_other_item(fd, NO_ITEM);
		}
		else
			success = write_other_item(fd, NO_ITEM);
		if (!success)
			return (false);
		i++;
	}
	return (true);
}

bool write_map_bin_entity(int fd,
						  t_map *map)
{
	int i;
	ssize_t tmp_size;
	int32_t equiped_weapon;
	t_entity_array array;
	t_entity entity;

	array = map->entity_array;
	tmp_size = sizeof(int32_t);
	if (write(fd, &array.nbr_entities, tmp_size) != tmp_size)
		return (false);
	i = 0;
	while (i < array.nbr_entities)
	{
		printo("\rMAP SAVER: Saving entity %d/%d   ",
			   i + 1, array.nbr_entities);
		entity = array.entities[i];
		tmp_size = sizeof(int32_t);
		if (write(fd, &entity.class, tmp_size) != tmp_size)
			return (false);
		tmp_size = sizeof(t_bunny_position);
		if (write(fd, &entity.pos, tmp_size) != tmp_size)
			return (false);
		tmp_size = sizeof(int32_t);
		if (write(fd, &entity.team, tmp_size) != tmp_size)
			return (false);
		if (!write_entity_inventory(fd, &entity.inventory))
			return (false);
		equiped_weapon = find_equiped_weapon(entity.equiped,
											 &entity.inventory);
		if (write(fd, &equiped_weapon, tmp_size) != tmp_size)
			return (false);
		i++;
	}
	printo("\n");
	return (true);
}