/**
 ** @file term_split_nlen.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "terminal_strsplit.h"

size_t term_split_nlen(char **split,
					   size_t max_len)
{
	size_t len;

	if (split == NULL)
		return (0);
	len = 0;
	while (split[len] != NULL && len < max_len)
		len++;
	return (len);
}