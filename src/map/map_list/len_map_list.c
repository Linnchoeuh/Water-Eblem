/**
 ** @file len_map_list.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "map.h"

size_t len_map_list(t_map_list *map_list)
{
	size_t i;

	i = 0;
	while (map_list->elem != NULL &&
		   map_list->elem[i] != NULL)
		i++;
	return (i);
}