/**
 ** @file new_sprite_bank.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "sprite.h"

t_sprite_bank *new_sprite_bank(void)
{
	t_sprite_bank *bank;

	bank = bunny_malloc(sizeof(t_sprite_bank));
	if (bank == NULL)
		return (NULL);
	bank->sprites = NULL;
	return (bank);
}