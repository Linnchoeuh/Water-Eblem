/**
 ** @file fill_format.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "printo.h"

static char *replace_elements(char **split,
					   va_list args)
{
	char *new_str;
	char *value_str;
	char **current_split;

	if ((new_str = printo_strdup("")) == NULL)
		return (NULL);
	current_split = split;
	size_t i = 0;
	while (current_split[0] != NULL)
	{
		value_str = convert_element(current_split[0], args);
		if (value_str == NULL)
		{
			free(new_str);
			return (NULL);
		}
		printo_str_append(&new_str, value_str);
		free(value_str);
		current_split = (&current_split[1]);
		i++;
	}
	return (new_str);
}

char *fill_format(char *str,
				va_list args)
{
	char *new_str;
	char **split;

	if ((split = split_str_by_format(str, NULL)) == NULL)
		return (NULL);
	new_str = replace_elements(split, args);
	printo_free_split(split);
	return (new_str);
}