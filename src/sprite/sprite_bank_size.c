/**
 ** @file sprite_bank_size.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "sprite.h"

size_t sprite_bank_size(t_sprite_bank *bank)
{
	size_t i;

	if (bank == NULL ||
		bank->sprites == NULL)
		return (0);
	i = 0;
	while (bank->sprites[i] != NULL)
		i++;
	return (i);
}