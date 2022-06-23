/**
 ** @file delete_map_elem.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "map.h"

void delete_map_elem(t_map_elem *elem)
{
	if (elem == NULL)
		return;
	if (elem->name != NULL)
		bunny_free(elem->name);
	if (elem->full_path != NULL)
		bunny_free(elem->full_path);
	bunny_free(elem);
}