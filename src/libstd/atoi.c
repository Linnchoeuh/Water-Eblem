/**
 ** @file atoi.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "libstd.h"

int std_atoi(const char *str)
{
	int result;
	int inverser;
	int count;

	inverser = -1;
	count = -inverser;
	result = 0;
	if (str[0] != '-')
	{
		if (IS_CHAR_NUMBER(str[0]) == 0)
			return (0);
		inverser = -inverser;
		count = 0;
	}
	while (IS_CHAR_NUMBER(str[count]) != 0)
	{
		result = result * 10 + str[count] - '0';
		++count;
	}
	return (result * inverser);
}
