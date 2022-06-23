/**
 ** @file read_entry.c
 ** @author Yann Lebib [lebib.yann@gmail.com]
 ** @brief
 **/

#include "keyboard.h"

static char *delete_text(t_keyboard *keyboard,
						 char *text)
{
	size_t nsize;

	if (text == NULL)
			return (text);
	nsize = strlen(text);
	if (keyboard->key_pressed[BKS_BACKSPACE] &&
		nsize > 0)
	{
		text = std_realloc(text, nsize);
		text[nsize - 1] = '\0';
	}
	return (text);
}

char *read_entry(t_keyboard *keyboard,
				 char **text,
				 bool number)
{
	char nchar[2];

	if (text == NULL || *text == NULL)
		return (NULL);
	nchar[1] = '\0';
	nchar[0] = interpret_keyboard(keyboard->key, keyboard->key_pressed);
	*text = delete_text(keyboard, *text);
	if (number && (nchar[0] < '0' || nchar[0] > '9'))
		return (*text);
	if (nchar[0] != '\0')
		term_str_append(text, nchar);
	return (*text);
}
