/**
 ** @file term_split_ndup.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "terminal_strsplit.h"

char **term_split_ndup(char **split,
					   size_t max_len)
{
	size_t i;
	char **split_copy;

	i = 0;
	split_copy = malloc((term_split_nlen(split, max_len) + 1) * sizeof(char*));
	if (split_copy == NULL)
		return (NULL);
	while (split[i] != NULL && i < max_len)
	{
		if ((split_copy[i] = term_strdup(split[i])) == NULL)
		{
			term_split_free(split_copy);
			return (NULL);
		}
		i++;
	}
	split_copy[i] = NULL;
	return (split_copy);
}