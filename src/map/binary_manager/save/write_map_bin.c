/**
 ** @file write_map_bin.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "map.h"

bool write_map_bin(int fd,
				   t_map *map)
{
	printo("MAP SAVER: Writing header...\n");
	if (!write_map_bin_header(fd, map))
		return (false);
	printo("MAP SAVER: Saving tile data...\n");
	if (!write_map_bin_tile_data(fd, map))
		return (false);
	printo("MAP SAVER: Saving entity data...\n");
	if (!write_map_bin_entity(fd, map))
		return (false);
	printo("MAP SAVER: Done.\n");
	return (true);
}