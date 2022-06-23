/**
 ** @file write_map_bin_header.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

/*
	WRITEN BINARY
	(char[8]) 8 bytes header that contains F_E_DATA (FIRE_EMBLEM_DATA)
	(int32_t) 4 bytes for map size x value
	(int32_t) 4 bytes for map size y value
*/

#include "map.h"

bool write_map_bin_header(int fd,
						  t_map *map)
{
	int8_t tmp_size;

	if (write(fd, MAP_HEADER_NAME, MAP_HEADER_SIZE) != MAP_HEADER_SIZE)
		return (false);
	tmp_size = sizeof(int32_t);
	if (write(fd, &map->sub_part->size.x, tmp_size) != tmp_size)
		return (false);
	if (write(fd, &map->sub_part->size.y, tmp_size) != tmp_size)
		return (false);
	return (true);
}
