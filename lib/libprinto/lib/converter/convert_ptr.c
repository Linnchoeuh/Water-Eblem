/**
 ** @file convert_ptr.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "printo_converter.h"

char *convert_ptr(va_list args)
{
	char *ptr_str;
	char *adr;

	if ((ptr_str = printo_strdup("0x")) == NULL)
		return (NULL);
	adr = int_converter_base((long) va_arg(args, long), PTR_BASE);
	if (adr == NULL || !printo_str_append(&ptr_str, adr))
	{
		(adr != NULL) ? free(adr) : 0;
		free(ptr_str);
		return (NULL);
	}
	free(adr);
	return (ptr_str);
}