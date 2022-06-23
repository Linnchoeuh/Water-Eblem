/**
 ** @file keyboard_struct.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __KEYBOARD_STRUCT_H__
#define __KEYBOARD_STRUCT_H__

#define IDLE_KEYS \
"abcdefghijklmnopqrstuvwxyz)&e\" ( e_c            ;, ':   -          +-*/    0123456789"

// BKS_LSHIFT
// BKS_RSHIFT
#define SHIFT_KEYS \
"ABCDEFGHIJKLMNOPQRSTUVWXYZ0123 5 789            .? 4/   6          +-*/    0123456789"

// BKS_LALT
// BKS_RALT
#define ALT_KEYS \
"abcdefghijklmnopqrstuvwxyz@&~# [ `\\^            ;, {:   |          +-*/    0123456789"

typedef struct	s_keyboard
{
	bool key[BKS_LAST_KEY];
	bool key_pressed[BKS_LAST_KEY];
	bool previous_key[BKS_LAST_KEY];
}				t_keyboard;

#endif