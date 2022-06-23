/**
 ** @file term_split_swap_str.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "terminal_strsplit.h"

void term_split_swap_str(char **split,
						 size_t pos1,
						 size_t pos2)
{
	size_t split_len;
	char *str_swap;

	split_len = term_split_len(split);
	if (pos1 > split_len || pos2 > split_len)
		return;
	str_swap = split[pos1];
	split[pos1] = split[pos2];
	split[pos2] = str_swap;
}