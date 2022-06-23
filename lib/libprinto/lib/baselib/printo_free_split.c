/**
 ** @file printo_free_split.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief Entirely free all the occurence if a char **
 ** At least require a NULL pointer at the end of the char **
 **/

#include "printo_baselib.h"

void printo_free_split(char **splitted)
{
	size_t i;

	if (splitted == NULL)
		return;
	i = 0;
	while (splitted[i] != NULL)
	{
		free(splitted[i]);
		++i;
	}
	free(splitted);
}