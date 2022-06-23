/**
 ** @file set_key_input.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "key_input.h"

void set_key_input(t_key_input *key_input,
				   t_keyboard *keyboard)
{
	key_input->lstick_hor = (keyboard->key[BKS_D] - keyboard->key[BKS_Q]);
	key_input->lstick_ver = (keyboard->key[BKS_S] - keyboard->key[BKS_Z]);
	if (keyboard->key_pressed[BKS_UP])
		key_input->up_arrow = true;
	if (keyboard->key_pressed[BKS_DOWN])
		key_input->down_arrow = true;
	if (keyboard->key_pressed[BKS_LEFT])
		key_input->left_arrow = true;
	if (keyboard->key_pressed[BKS_RIGHT])
		key_input->right_arrow = true;
	if (keyboard->key_pressed[BKS_PAGEUP])
		key_input->pg_up = true;
	if (keyboard->key_pressed[BKS_PAGEDOWN])
		key_input->pg_down = true;
	if (keyboard->key_pressed[BKS_ESCAPE])
		key_input->echap = true;
	if (keyboard->key_pressed[BKS_RETURN])
		key_input->enter = true;
}