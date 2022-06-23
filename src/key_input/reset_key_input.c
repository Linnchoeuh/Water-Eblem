/**
 ** @file reset_key_input.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "key_input.h"

void reset_key_input(t_key_input *key_input)
{
	key_input->up_arrow = false;
	key_input->down_arrow = false;
	key_input->left_arrow = false;
	key_input->right_arrow = false;
	key_input->enter = false;
	key_input->echap = false;
	key_input->pg_up = false;
	key_input->pg_down = false;
	key_input->lstick_ver = 0;
	key_input->lstick_hor = 0;
}