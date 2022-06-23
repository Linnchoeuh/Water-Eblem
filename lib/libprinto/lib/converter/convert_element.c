/**
 ** @file convert_element.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "printo_converter.h"
#include "printo_global.h"

char *convert_element(char *elem,
					va_list args)
{
	size_t i;

	if (elem[0] != '%')
		return (printo_strdup(elem));
	elem++;
	if (elem[0] == FLAGS[F_PERCENT])
		return (printo_strdup("%"));
	i = 0;
	while (i < NB_OF_CONVERTER)
	{
		if (elem[0] == FLAGS[i + 1])
			return(CONVERT_FUNC[i](args));
		i++;
	}
	return (NULL);
}