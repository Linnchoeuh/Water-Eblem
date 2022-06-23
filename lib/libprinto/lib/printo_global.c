/**
 ** @file printo_global.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "printo_converter.h"
#include "printo_macro.h"

t_convert_func CONVERT_FUNC[NB_OF_CONVERTER] = {
	convert_int,
	convert_float,
	convert_str,
	convert_char,
	convert_bool,
	convert_ptr
};

char FLAGS[NB_OF_FLAGS] = "%dfscBp";