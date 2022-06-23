/**
 ** @file memcpy.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "libstd.h"

void		*std_memcpy(void *restrict		destination,
			    const void *restrict	source,
			    size_t			size)
{
  size_t	i;
  char		*dest;
  char		*src;

  i = 0;
  dest = (char *) destination;
  src = (char *) source;
  while (i < size)
    {
      dest[i] = src[i];
      ++i;
    }
  return ((void *) dest);
}

