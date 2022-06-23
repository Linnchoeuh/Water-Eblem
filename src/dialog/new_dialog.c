/**
 ** @file new_dialog.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "dialog.h"

t_dialog new_dialog(char *msg,
					t_bunny_font *font,
					t_bunny_music *text_sound,
					t_bunny_music *valid_sound)
{
	t_dialog dialog;

	reset_dialog_status(&dialog);
	dialog.msg = msg;
	dialog.text_sound = text_sound;
	dialog.valid_sound = valid_sound;
	dialog.font = font;
	set_dialog_speed(&dialog, 30);
	return (dialog);
}