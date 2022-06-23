/**
 ** @file convert_float.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "printo_converter.h"

#define MAX_FLOATING_NUM 6

void round_result(char *str,
				  double float_part)
{
	size_t str_pos;
	bool increment;

	float_part *= 10;
	if (float_part == 0 || float_part < 5)
		return;
	increment = true;
	str_pos = printo_strlen(str) - 1;
	while (1)
	{
		if (!increment || str_pos == 0)
			return;
		increment = (str[str_pos] == '9');
		str[str_pos] = (increment) ? '0' : str[str_pos] + 1;
		str_pos--;
		str_pos -= (str[str_pos] == '.');
	}
}

char *convert_float(va_list args)
{
	char *str;
	char c[2];
	double num;
	long int_part;
	double float_part;
	int float_num_count;

	num = va_arg(args, double);
	int_part = (long) num;
	float_part = PRINTO_ABS(num - (double) int_part);
	str = int_converter_base(int_part, NUM_BASE);
	printo_str_append(&str, ".");
	c[1] = '\0';
	float_num_count = 0;
	while (float_num_count < MAX_FLOATING_NUM)
	{
		float_part *= 10;
		int_part = ((long) float_part);
		float_part -= (double) int_part;
		c[0] = '0' + int_part;
		printo_str_append(&str, c);
		float_num_count++;
	}
	round_result(str, float_part);
	return (str);
}