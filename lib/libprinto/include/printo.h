/**
 ** @file printo.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef		__PRINTO_H__
#define		__PRINTO_H__

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdbool.h>
#include	<stdarg.h>

#include	"printo_baselib.h"
#include 	"printo_macro.h"
#include 	"printo_converter.h"

/**
 * @brief This function is a printf like. It work the same way as printo but
 * the otuput will be always STDOUT
 *
 * @tparam %% to write a %.
 * @tparam %d for an int/long.
 * @tparam %f for a float/double.
 * @tparam %s for a str.
 * @tparam %c for a char.
 * @tparam %B for a boolean.
 * @tparam %p for an adress.
 *
 * @param text The text with the format.
 * @param ... The value to replace the %format
 */
void printo(char *text,
			...);


/**
 * @brief This function is a printf like.
 *
 * @tparam %% to write a %.
 * @tparam %d for an int/long.
 * @tparam %f for a float/double.
 * @tparam %s for a str.
 * @tparam %c for a char.
 * @tparam %B for a boolean.
 * @tparam %p for an adress.
 *
 * @param fd Where you want to write it.
 * @param text The text with the format.
 * @param ... The value to replace the %format
 */
void fprinto(int fd,
			 char *text,
			 ...);


/**
 * @brief Take an str with %formats and return a str with
 * %format by value in the va_list.
 *
 * @tparam %% to write a %.
 * @tparam %d for an int/long.
 * @tparam %f for a float/double.
 * @tparam %s for a str.
 * @tparam %c for a char.
 * @tparam %B for a boolean.
 * @tparam %p for an adress.
 *
 * @param text The text with the format.
 * @param ... The value to replace the %format
 *
 * @return char* with replaced value in place of %format and NULL on failure.
 */
char *generate_str(char *text,
				   ...);


/**
 * @brief Replace the %format by the corresponding value in va_arg.
 *
 * @param str The str with their %format in.
 * @param args va_list that contain values to replace the %format.
 *
 * @return char* with replaced value in place of %format
 * and NULL on failure.
 */
char *fill_format(char *str,
				va_list args);


/**
 * @brief Split a char* at each %format found.
 *
 * @param str The str with their %format in.
 * @param split_len You can get the len of the split,
 * but you can set at NULL if you don't want it.
 *
 * @return char** with NULL at the end. re
 */
char **split_str_by_format(char *str,
						 ssize_t *split_len);

/**
 * @brief Add at the next of target str, the merge content.
 * The fusion of this will be in target.
 *
 * @param target A overreferenced char* that will be edited.
 * @param merge The part that will be added at the target
 *
 * @return true on success, false on failure
 */
bool printo_str_append(char **target,
				   		char *merge);

#endif  /*      __PRINTO_H__    */

