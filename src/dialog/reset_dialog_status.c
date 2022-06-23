/**
 ** @file reset_dialog_status.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "dialog.h"

void reset_dialog_status(t_dialog *dialog)
{
	dialog->char_pos = 0;
	dialog->prev_char_pos = 0;
	dialog->ended = false;
	dialog->hide = false;
}