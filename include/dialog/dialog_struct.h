/**
 ** @file dialog_struct.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __DIALOG_STRUCT_H__
#define __DIALOG_STRUCT_H__

#include <lapin.h>

typedef struct	s_dialog
{
	char *msg;
	bool ended;
	bool hide;
	double char_pos;
	double prev_char_pos;
	double char_par_sec;
	t_bunny_font *font;
	t_bunny_music *text_sound;
	t_bunny_music *valid_sound;
}				t_dialog;

typedef struct	s_conv
{
	bool hide;
	t_dialog *dialog;
	unsigned int nbr_dialog;
	unsigned int current_dialog;
}				t_conv;

#endif