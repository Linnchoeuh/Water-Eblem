/**
 ** @file convert_str.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "printo_converter.h"

char *convert_str(va_list args)
{
	char *str;

	str = (char*) va_arg(args, char*);
	return (printo_strdup(str));
}