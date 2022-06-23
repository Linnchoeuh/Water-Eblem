/**
 ** @file term_strcasecmp.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "libstd.h"

int	term_strcasecmp(const char	*a,
					const char	*b)
{
	size_t i;

	i = 0;
	while (TERM_TOLOWER(a[i]) == TERM_TOLOWER(b[i]) &&
	    	a[i] != 0 && b[i] != 0)
		++i;
  	return (TERM_TOLOWER(a[i]) - TERM_TOLOWER(b[i]));
}

