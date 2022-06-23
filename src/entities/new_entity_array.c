/**
 ** @file new_entity_array.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "entities.h"

t_entity_array new_entity_array(void)
{
	t_entity_array entity_array;

	entity_array.entities = NULL;
	entity_array.nbr_entities = 0;
	return (entity_array);
}