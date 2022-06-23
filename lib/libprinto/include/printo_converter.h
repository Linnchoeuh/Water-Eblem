/**
 ** @file printo_converter.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef		__PRINTO_CONVERTER_H__
#define		__PRINTO_CONVERTER_H__

#include	"printo.h"

char *convert_element(char *elem,
					va_list args);

char *convert_int(va_list args);

/**
 * @brief Take a number and convert into an str a the given base
 *
 * @param num The number you want to convert
 * @param base Which base you want can't be upper than 36.
 * @return char* that represent the number
 */
char *int_converter_base(long num,
					int base);

char *convert_float(va_list args);

char *convert_str(va_list args);

char *convert_char(va_list args);

char *convert_bool(va_list args);

char *convert_ptr(va_list args);

typedef enum e_convert_func_type
  {
	CONV_INT,
	CONV_FLOAT,
	CONV_STR,
	CONV_CHAR,
	CONV_BOOL,
	CONV_PTR,
    NB_OF_CONVERTER // always be at the end
  }			t_convert_func_type;

typedef char* (*t_convert_func)(va_list args);

#endif  /*      __PRINTO_CONVERTER_H__    */