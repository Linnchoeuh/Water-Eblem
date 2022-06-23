/**
 ** @file term_strchr.c
 ** @author Ethan Nguyen
 ** @brief
 **/

#include "libstd.h"

char *term_strchr(const char *s,
                  int c)
{
    while (*s)
    {
        if (*s == c)
            return ((char *)s);
        ++s;
    }
    return (NULL);
}