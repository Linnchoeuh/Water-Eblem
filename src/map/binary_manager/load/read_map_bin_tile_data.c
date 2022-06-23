/**
 ** @file read_map_bin_tile_data.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "map.h"

bool read_map_bin_tile_data(int fd,
							t_map *map)
{
	size_t i;
	size_t j;
	size_t k;
	size_t nbr_tile;
	size_t nbr_layer;
	uint16_t id;
	uint64_t tmp;
	t_tile_array *array;

	map->map_asset = new_sprite_bank();
	if (map->map_asset == NULL)
		return (false);
	read(fd, &tmp, sizeof(uint64_t));
	printo("%d\n", tmp);
	i = 0;
	while (i < tmp)
	{
		if (!sprite_bank_add_sprite(map->map_asset,
				read_sprite_bin(fd)))
			return (false);
		i++;
	}
	nbr_tile = map->sub_part->size.x * map->sub_part->size.y;
	i = 0;
	while (i < 2)
	{
		array = ((i == 0) ? map->sub_part : map->over_part);
		j = 0;
		while (array->tiles[j] != NULL)
		{
			printo("\rMAP LOADER: Loading tile %d/%d %d/2   ",
				j + 1, nbr_tile, i + 1);
			read(fd, &array->tiles[j]->is_block, sizeof(bool));
			read(fd, &nbr_layer, sizeof(uint64_t));
			k = 0;
			// printo("%d\n", nbr_layer);
			while (k < nbr_layer)
			{
				read(fd, &id, sizeof(uint16_t));
				tile_add_layer(array->tiles[j], map->map_asset->sprites[id]);
				read(fd, &array->tiles[j]->layers[k]->rotation, sizeof(double));
				read(fd, &array->tiles[j]->layers[k]->mirror, sizeof(bool));
				k++;
			}
			j++;
		}
		i++;
	}
	printo("\n");
	return (true);
}