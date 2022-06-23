/**
 ** @file printo.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "printo.h"

void printo(char *text,
			 ...)
{
	char *assembled_text;
	va_list args;

	va_start(args, text);
	assembled_text = fill_format(text, args);
	va_end(args);
	if (assembled_text != NULL)
	{
		write(STDOUT_FILENO, assembled_text, printo_strlen(assembled_text));
		free(assembled_text);
	}
}