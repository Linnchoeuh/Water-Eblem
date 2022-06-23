/**
 ** @file term_str_chain_fuse.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "libstd.h"

char *term_str_chain_fuse(ssize_t len, ...)
{
	char *new_str;
	char *get_str;
	ssize_t i;
	va_list ap;

	if (len == 0)
		return (term_strdup(""));
	va_start(ap, len);
	if ((new_str = term_strdup((char*) va_arg(ap, char*))) == NULL)
		return (NULL);
	i = 1;
	while ((len == -1 || i < len) &&
		(get_str = (char*) va_arg(ap, char*)) != NULL)
	{
		term_str_append(&new_str, get_str);
		i++;
	}
	va_end(ap);
	return (new_str);
}