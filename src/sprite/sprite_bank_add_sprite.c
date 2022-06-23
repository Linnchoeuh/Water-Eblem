/**
 ** @file sprite_bank_add_sprite.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "sprite.h"

bool sprite_bank_add_sprite(t_sprite_bank *bank,
							t_sprite *new_sprite)
{
	size_t size;
	t_sprite **new_bank;

	if (new_sprite == NULL)
		return (false);
	size = sprite_bank_size(bank);
	new_bank = bunny_malloc((size + 2) * sizeof(t_sprite*));
	if (new_bank == NULL)
		return (false);
	std_memcpy(new_bank, bank->sprites, size * sizeof(t_sprite*));
	new_bank[size] = new_sprite;
	new_bank[size + 1] = NULL;
	bunny_free(bank->sprites);
	bank->sprites = new_bank;
	return (true);
}