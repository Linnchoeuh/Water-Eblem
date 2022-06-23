/**
 ** @file realloc.c
 ** @author Ethan Nguyen
 ** @brief
 **/

#include "libstd.h"

void            *std_realloc(void       *ptr,
                             size_t     new_size)
{

  void		*new_ptr;
  size_t	size;

  new_ptr = NULL;
  if (!ptr)
    return (malloc(new_size));
  else if ((size = malloc_usable_size(ptr)) >= new_size)
    return (ptr);
  else if (new_size != 0)
    {
      if ((new_ptr = malloc(new_size)) == NULL)
        return (NULL);
      std_memcpy(new_ptr, ptr, malloc_usable_size(ptr));
    }
  free(ptr);
  return (new_ptr);
}
