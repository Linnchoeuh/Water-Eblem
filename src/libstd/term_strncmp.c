/**
 ** @file term_strncmp.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "libstd.h"

int		term_strncmp(const char	*first,
					 const char	*second,
					 size_t		length)
{
	size_t	i;

	i = 0;
	while (first[i] == second[i] && first[i] != '\0' &&
		   i < length)
		++i;
	if (i == length)
		return (0);
	return (first[i] - second[i]);
}

