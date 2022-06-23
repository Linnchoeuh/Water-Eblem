/**
 ** @file term_strdup.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "libstd.h"

char *term_strdup(char *s)
{
	int  i;
	char *str;

	i = 0;
	if ((str = malloc(term_strlen(s) + 1)) == NULL)
		return (NULL);
	while (s[i] != 0)
	{
		str[i] = s[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}

