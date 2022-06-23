/**
 ** @file dialog.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __DIALOG_H__
#define __DIALOG_H__

#include <lapin.h>

#include "dialog_struct.h"
#include "audio.h"
#include "font.h"
#include "framerate.h"
#include "ui.h"

t_dialog new_dialog(char *msg,
					t_bunny_font *font,
					t_bunny_music *text_sound,
					t_bunny_music *valid_sound);

void set_dialog_speed(t_dialog *msg,
					  double char_par_sec);

void reset_dialog_status(t_dialog *msg);

bool display_dialog(t_bunny_buffer *buf,
					t_dialog *msg,
					bool trigger,
					double delta_time);

t_conv		*new_conv(void);

bool		add_dialog(t_conv		*conv,
			   t_dialog		new_dialog);

void            set_conv_speed(t_conv		*conv,
                               double		char_par_sec);

void		reset_conv_status(t_conv       *conv);

bool            display_conv(t_bunny_buffer     *buf,
                             t_conv             *conv,
                             bool               trigger,
                             double             delta_time);

void            delete_conv(t_conv		*conv);

#endif