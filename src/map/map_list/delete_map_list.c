/**
 ** @file delete_map_list.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "map.h"

void delete_map_list(t_map_list *map_list)
{
	size_t i;

	if (map_list == NULL)
		return;
	i = 0;
	while (map_list != NULL &&
			map_list->elem[i] != NULL)
	{
		delete_map_elem(map_list->elem[i]);
		i++;
	}
	if (map_list->elem != NULL)
		bunny_free(map_list->elem);
	bunny_free(map_list);
}