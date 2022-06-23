/**
 ** @file read_map_bin_header.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "map.h"

bool read_map_bin_header(int fd,
						 t_bunny_position *map_size)
{
	char header_name[8];
	int8_t tmp_size;

	if (read(fd, header_name, MAP_HEADER_SIZE) != MAP_HEADER_SIZE)
		return (false);
	if (term_strncmp(header_name, MAP_HEADER_NAME, MAP_HEADER_SIZE) != 0)
		return (false);
	tmp_size = sizeof(int32_t);
	if (read(fd, &map_size->x, tmp_size) != tmp_size)
		return (false);
	if (read(fd, &map_size->y, tmp_size) != tmp_size)
		return (false);
	return (true);
}