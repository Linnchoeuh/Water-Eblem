/**
 ** @file generate_str.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "printo.h"

char *generate_str(char *text,
				   ...)
{
	char *assembled_text;
	va_list args;

	va_start(args, text);
	assembled_text = fill_format(text, args);
	va_end(args);
	return (assembled_text);
}