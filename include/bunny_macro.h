/**
 ** @file bunny_macro.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __BUNNY_MACRO_H__
#define __BUNNY_MACRO_H__

#define SETPOS(__posx, __posy) \
	({t_bunny_position __pos__; \
	__pos__.x = (__posx);__pos__.y = (__posy);__pos__;})

#define SETPOS_ACC(__posx, __posy) \
	({t_bunny_accurate_position __pos__; \
	__pos__.x = (__posx);__pos__.y = (__posy);__pos__;})

#define SAMEPOS(pos1, pos2) \
	((pos1).x == (pos2).x && (pos1).y == (pos2).y)

#define SETAREA(__x, __y, __w, __h) \
	({t_bunny_area __area__; \
	__area__.x = (__x); \
	__area__.y = (__y); \
	__area__.w = (__w); \
	__area__.h = (__h); \
	__area__;})

#define SETAREA_ACC(__x, __y, __w, __h) \
	({t_bunny_accurate_area __area__; \
	__area__.x = (__x); \
	__area__.y = (__y); \
	__area__.w = (__w); \
	__area__.h = (__h); \
	__area__;})

#define BI_TO_ONE_DIMENSION(__x, __y, __width) \
	((__x) + ((__y) * (__width)))

#define ROUND_NUM(__nbr) ({ \
	long __integer_part; \
	double __floating_part; \
\
	__integer_part = (__nbr); \
	__floating_part = (__nbr) - (__integer_part); \
	((__integer_part) + ((__floating_part) >= 0.5)); \
})

#define INVENTORY_SIZE 4

#endif