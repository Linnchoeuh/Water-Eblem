/**
 ** @file key_input.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __KEY_INPUT_H__
#define __KEY_INPUT_H__

#include "key_input_struct.h"
#include "keyboard_struct.h"

void reset_key_input(t_key_input *key_input);

void set_key_input(t_key_input *key_input,
				   t_keyboard *keyboard);

#endif