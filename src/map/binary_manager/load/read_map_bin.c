/**
 ** @file read_map_bin.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "map.h"

t_map *read_map_bin(int fd)
{
	t_map *map;
	t_bunny_position map_size;

	printo("MAP LOADER: Reading header...\n");
	if (!read_map_bin_header(fd, &map_size))
		return (NULL);
	map = new_map(map_size);
	if (map == NULL)
		return (NULL);
	printo("MAP LOADER: Reading tile data...\n");
	if (!read_map_bin_tile_data(fd, map))
		return (false);
	printo("MAP LOADER: Reading entity data...\n");
	if (!read_map_bin_entity(fd, map))
		return (false);
	printo("MAP LOADER: Done.\n");
	return (map);
}