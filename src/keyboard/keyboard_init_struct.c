/**
 ** @file keyboard_init_struct.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "keyboard.h"

void keyboard_init_struct(t_keyboard *keyboard)
{
	int i;

	i = 0;
	while (i < BKS_LAST_KEY)
	{
		keyboard->key[i] = false;
		keyboard->previous_key[i] = false;
		keyboard->key_pressed[i] = false;
		i++;
	}
}