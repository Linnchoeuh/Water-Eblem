/**
 ** @file key_input_struct.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __KEY_INPUT_STRUCT_H__
#define __KEY_INPUT_STRUCT_H__

#include <lapin.h>

typedef struct	s_key_input
{
	bool up_arrow;
	bool down_arrow;
	bool left_arrow;
	bool right_arrow;
	bool enter;
	bool echap;
	bool pg_up;
	bool pg_down;
	double lstick_ver;
	double lstick_hor;
}				t_key_input;

#endif