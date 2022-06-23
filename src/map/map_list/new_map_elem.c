/**
 ** @file new_map_elem.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "map.h"

t_map_elem *new_map_elem(char *name,
						 char *full_path,
						 t_bunny_position map_size)
{
	t_map_elem *elem;

	elem = bunny_malloc(sizeof(t_map_elem));
	if (elem == NULL)
		return (NULL);
	elem->name = name;
	elem->full_path = full_path;
	elem->map_size = map_size;
	return (elem);
}
