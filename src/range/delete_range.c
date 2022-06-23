/**
 ** @file delete_range.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "range.h"

void delete_range(t_range *range)
{
	if (range == NULL)
		return;
	bunny_free(range->pos);
	bunny_free(range);
}