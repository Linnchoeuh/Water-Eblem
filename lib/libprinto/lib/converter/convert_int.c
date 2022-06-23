/**
 ** @file convert_int.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "printo_converter.h"

char *convert_int(va_list args)
{
	return (int_converter_base((long) va_arg(args, long), NUM_BASE));
}