/**
 ** @file int_converter_base.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "printo_converter.h"

#define NUM_BASE 10

static bool append_number(char **str,
					long num,
					int base)
{
	bool state;
	char nums[36] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char c[2] = {nums[num % base], '\0'};

	if (num > base - 1)
		state = append_number(str, num / base, base);
	state = printo_str_append(str, c);
	return (state);
}

char *int_converter_base(long num,
					int base)
{
	char *str;

	if (base > 36)
		return (NULL);
	if (num < 0)
    {
      	num = -num;
      	str = printo_strdup("-");
    }
	else
		str = printo_strdup("");
	if (str == NULL || !append_number(&str, num, base))
	{
		(str != NULL) ? free(str) : 0;
		return (NULL);
	}
	return (str);
}