/**
 ** @file term_str_append.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "libstd.h"

bool term_str_append(char **target,
				   		char *merge)
{
	char *new_str;

	if ((new_str = term_str_fuse(*target, merge)) == NULL)
		return (false);
	free(*target);
	*target = new_str;
	return (true);
}