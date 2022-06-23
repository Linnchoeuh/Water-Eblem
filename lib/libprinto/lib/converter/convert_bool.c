/**
 ** @file convert_bool.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "printo_converter.h"

char *convert_bool(va_list args)
{
	if ((int) va_arg(args, int))
		return (printo_strdup("true"));
	return (printo_strdup("false"));
}