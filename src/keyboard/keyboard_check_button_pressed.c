/**
 ** @file keyboard_check_button_pressed.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "keyboard.h"

void keyboard_check_button_pressed(t_keyboard *keyboard)
{
	int i;

	i = 0;
	while (i < BKS_LAST_KEY)
	{
		keyboard->key_pressed[i] =
			(keyboard->key[i] && !keyboard->previous_key[i]);
		keyboard->previous_key[i] = keyboard->key[i];
		i++;
	}
}