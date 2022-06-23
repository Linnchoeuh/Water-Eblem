/**
 ** @file sprite_bank_append.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "sprite.h"

bool sprite_bank_append(t_sprite_bank *dest_bank,
						t_sprite_bank *src_bank)
{
	size_t i;

	if (src_bank == NULL || src_bank->sprites == NULL ||
		dest_bank == NULL)
		return (false);
	i = 0;
	while (src_bank->sprites[i] != NULL)
	{
		sprite_bank_add_sprite(dest_bank, src_bank->sprites[i]);
		i++;
	}
	return (true);
}