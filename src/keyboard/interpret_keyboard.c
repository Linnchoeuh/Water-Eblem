/**
 ** @file interpret_keyboard.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "keyboard.h"

bool is_a_char(int id)
{
	int i;
	int excluded_keys[39] = {
		BKS_ESCAPE,
		BKS_LCONTROL,
		BKS_LSHIFT,
		BKS_LALT,
		BKS_LSYSTEM,
		BKS_RCONTROL,
		BKS_RSHIFT,
		BKS_RALT,
		BKS_RSYSTEM,
		BKS_MENU,
		BKS_RETURN,
		BKS_BACKSPACE,
		BKS_TAB,
		BKS_PAGEUP,
		BKS_PAGEDOWN,
		BKS_END,
		BKS_HOME,
		BKS_INSERT,
		BKS_DELETE,
		BKS_LEFT,
		BKS_RIGHT,
		BKS_UP,
		BKS_DOWN,
		BKS_F1,
		BKS_F2,
		BKS_F3,
		BKS_F4,
		BKS_F5,
		BKS_F6,
		BKS_F7,
		BKS_F8,
		BKS_F9,
		BKS_F10,
		BKS_F11,
		BKS_F12,
		BKS_F13,
		BKS_F14,
		BKS_F15,
		BKS_PAUSE};
	i = 0;
	while (i < 39)
	{
		if (id == excluded_keys[i])
			return (false);
		i++;
	}
	return (true);
}

char interpret_keyboard(const bool *keys,
			const bool *keys_pressed)
{
	int i;
	int key_str_len;
	char *key_range;

	key_range = IDLE_KEYS;
	if (keys[BKS_RSHIFT] || keys[BKS_LSHIFT])
		key_range = SHIFT_KEYS;
	else if (keys[BKS_LALT] || keys[BKS_RALT])
		key_range = ALT_KEYS;
	key_str_len = term_strlen(key_range);
	i = 0;
	while (i < key_str_len)
	{
	  if (keys_pressed[i] && is_a_char(i))
		{
		  if (key_range[i] == ' ' &&
		      i == BKS_SPACE)
		    return (key_range[i]);
		  else if (key_range[i] != ' ')
		    return (key_range[i]);
		}
	  i++;
	}
	return (0);
}
