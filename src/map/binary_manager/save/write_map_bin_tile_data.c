/**
 ** @file write_map_bin_tile_data.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "map.h"

static t_sprite_bank *reference_map_sprites(t_map *map)
{
	bool stop_check;
	size_t i;
	size_t j;
	size_t k;
	size_t l;
	size_t sprite_len;
	t_animation **layers;
	t_sprite_bank *bank;

	bank = new_sprite_bank();
	if (bank == NULL)
		return (NULL);
	sprite_len = 0;
	while (map->map_asset->sprites[sprite_len] != NULL)
		sprite_len++;
	i = 0;
	while (map->map_asset->sprites[i] != NULL)
	{
		j = 0;
		printo("\rMAP SAVER: Checking tile sprite %d/%d", i + 1, sprite_len);
		stop_check = false;
		while (map->sub_part->tiles[j] != NULL &&
				!stop_check)
		{
			k = 0;
			while (!stop_check && k < 2)
			{
				l = 0;
				layers = ((k == 0) ? map->sub_part->tiles[j]->layers :
									map->over_part->tiles[j]->layers);
				while (!stop_check &&
					layers != NULL && layers[l] != NULL)
				{
					if (layers[l]->sprite == map->map_asset->sprites[i])
					{
						sprite_bank_add_sprite(bank,
							map->map_asset->sprites[i]);
						stop_check = true;
					}
					l++;
				}
				k++;
			}
			j++;
		}
		i++;
	}
	printo("\n");
	return (bank);
}

uint16_t find_sprite_id(t_animation *anim,
						t_sprite_bank *bank)
{
	uint16_t i;

	i = 0;
	while (bank->sprites != NULL &&
		bank->sprites[i] != NULL)
	{
		if (anim->sprite == bank->sprites[i])
			return (i);
		i++;
	}
	return (i);
}

bool write_map_bin_tile_data(int fd,
							 t_map *map)
{
	size_t i;
	size_t j;
	size_t k;
	size_t nbr_tile;
	size_t nbr_layer;
	uint16_t id;
	t_animation *anim;
	t_tile_array *array;
	t_sprite_bank *bank;

	bank = reference_map_sprites(map);
	if (bank == NULL)
		return (false);
	i = sprite_bank_size(bank);
	write(fd, &i, sizeof(uint64_t));
	i = 0;
	while (bank->sprites != NULL &&
			bank->sprites[i] != NULL)
	{
		write_sprite_bin(fd, bank->sprites[i]);
		i++;
	}
	i = 0;
	nbr_tile = map->sub_part->size.x * map->sub_part->size.y;
	while (i < 2)
	{
		array = ((i == 0) ? map->sub_part : map->over_part);
		j = 0;
		while (array->tiles[j] != NULL)
		{
			printo("\rMAP SAVER: Saving tile %d/%d %d/2   ",
				j + 1, nbr_tile, i + 1);
			write(fd, &array->tiles[j]->is_block, sizeof(bool));
			nbr_layer = count_tile_layers(array->tiles[j]);
			write(fd, &nbr_layer, sizeof(uint64_t));
			k = 0;
			while (k < nbr_layer)
			{
				anim = array->tiles[j]->layers[k];
				id = find_sprite_id(anim, bank);
				write(fd, &id, sizeof(uint16_t));
				write(fd, &anim->rotation, sizeof(double));
				write(fd, &anim->mirror, sizeof(bool));
				k++;
			}
			j++;
		}
		i++;
	}
	printo("\n");
	return (true);
}