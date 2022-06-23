/**
 ** @file libstd.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __LIBSTD_H__
#define __LIBSTD_H__

#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdarg.h>
#include <unistd.h>

#define TERM_TOLOWER(c) (((c) >= 'A' && (c) <= 'Z') ? ((c) + ('a' - 'A')) : (c))
#define TERM_TOUPPER(c) (((c) >= 'a' && (c) <= 'z') ? ((c) - ('a' - 'A')) : (c))
#define		IS_CHAR_NUMBER(nbr) ((nbr) >= '0' && (nbr) <= '9' ? 1 : 0)

void *std_memcpy(void *restrict	destination,
				 const void *restrict source,
				 size_t	size);

void *std_realloc(void *ptr,
				  size_t new_size);

int std_atoi(const char *str);

char *term_strdup(char *s);

char *term_strndup(const char *s,
			      size_t n);

size_t term_strlen(char	*s);

size_t term_strnlen(const char *s,
			    	size_t n);

int	term_strcmp(const char *str1,
			    const char *str2);

int	term_strncmp(const char *first,
			     const char	*second,
			     size_t	length);

int	term_strcasecmp(const char	*a,
					const char	*b);

/**
 * @brief Merge two (char *) into one.
 *
 * @param str1 First one.
 * @param str2 Second one.
 * @return char* on success,
 * NULL if the memory allocation went wrong.
 */
char		*term_str_fuse(char	*str1,
						   char	*str2);

/**
 * @brief Add at the next of target str, the merge content.
 * The fusion of this will be in target.
 *
 * @param target A overreferenced char* that will be edited.
 * @param merge The part that will be added at the target
 *
 * @return true on success, false on failure
 */
bool term_str_append(char **target,
				   	 char *merge);

/**
 * @brief Makes possible to fuse more than two str a the same time.
 * You can precise how many element you want to fuse in len,
 * but also set at -1 and just put a NULL a the of your list of str.
 *
 * @param len The amount of str to fuse. -1 to fuse them all,
 * but you have to add a NULL at the end of yout list.
 * @param ... Only expect str (char *) or NULL.
 *
 * @return char* The fusion of all the str given.
 * NULL on failure.
 */
char *term_str_chain_fuse(ssize_t len, ...);

char *term_strrchr(const char *s,
                   int c);

char *term_strchr(const char *s,
                  int c);

#endif