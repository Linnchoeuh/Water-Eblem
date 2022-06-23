/**
 ** @file convert_char.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "printo_converter.h"

char *convert_char(va_list args)
{
	char c;

	c = (int) va_arg(args, int);
	return (printo_strdup(&c));
}