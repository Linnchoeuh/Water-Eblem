/**
 ** @file term_strcmp.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "libstd.h"

int	term_strcmp(const char *str1,
				const char *str2)
{
	int i;

	i = 0;
	while (str1[i] == str2[i] && str1[i] != '\0')
		i++;
	return (str2[i] - str1[i]);
}

