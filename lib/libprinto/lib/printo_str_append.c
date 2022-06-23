/**
 ** @file printo_str_append.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "printo.h"

bool printo_str_append(char **target,
				   		char *merge)
{
	char *new_str;
	size_t i;
	size_t target_len;
	size_t new_len;

	target_len = printo_strlen(*target);
	new_len = target_len + printo_strlen(merge);
	if ((new_str = malloc(new_len + 1)) == NULL)
		return (false);
	i = 0;
	while ((*target)[i] != '\0')
	{
		new_str[i] = (*target)[i];
		i++;
	}
	while (i < new_len)
	{
		new_str[i] = merge[i - target_len];
		i++;
	}
	new_str[i] = '\0';
	free(*target);
	*target = new_str;
	return (true);
}