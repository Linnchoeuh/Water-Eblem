/**
 ** @file delete_sprite_bank.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "sprite.h"

void delete_sprite_bank(t_sprite_bank *bank)
{
	size_t i;

	if (bank == NULL)
		return;
	i = 0;
	while (bank->sprites != NULL &&
		bank->sprites[i] != NULL)
	{
		delete_sprite_struct(bank->sprites[i]);
		i++;
	}
	if (bank->sprites != NULL)
		bunny_free(bank->sprites);
	bunny_free(bank);
}