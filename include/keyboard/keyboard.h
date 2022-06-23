/**
 ** @file keyboard.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#include <lapin.h>

#include "keyboard_struct.h"
#include "libstd.h"

void keyboard_init_struct(t_keyboard *keyboard);

void keyboard_check_button_pressed(t_keyboard *keyboard);

char interpret_keyboard(const bool *keys,
			const bool *keys_pressed);

char *read_entry(t_keyboard *keyboard,
                 char **text,
                 bool number);

#endif
