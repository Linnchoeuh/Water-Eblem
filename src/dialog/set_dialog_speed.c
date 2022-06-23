/**
 ** @file set_dialog_speed.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "dialog.h"

void set_dialog_speed(t_dialog *dialog,
					   double char_par_sec)
{
	dialog->char_par_sec = char_par_sec / BASE_UPDATE_PER_SECOND;
}