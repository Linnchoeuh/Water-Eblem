/**
 ** @file term_strrchr.c
 ** @author Ethan Nguyen
 ** @brief
 **/

#include "libstd.h"

char *term_strrchr(const char *s,
                   int c)
{
    const char *found;
    const char *p;

    found = NULL;
    while ((p = term_strchr(s, c)) != NULL)
    {
        found = p;
        s = p + 1;
    }
    return ((char *)found);
}