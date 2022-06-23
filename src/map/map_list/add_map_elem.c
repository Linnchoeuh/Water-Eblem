/**
 ** @file add_map_elem.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "map.h"

void add_map_elem(t_map_list *map_list,
				  t_map_elem *new_elem)
{
	size_t size;

	size = len_map_list(map_list);
	map_list->elem = std_realloc(map_list->elem,
		(size + 2) * sizeof(t_map_elem*));
	map_list->elem[size] = new_elem;
	map_list->elem[size + 1] = NULL;
}