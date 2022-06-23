/**
 ** @file printo_macro.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef		__PRINTO_MACRO_H__
#define		__PRINTO_MACRO_H__

#define 	PRINTO_ABS(n) (((n) < 0) ? (-(n)) : (n))
#define 	NUM_BASE 10
#define 	PTR_BASE 16

typedef enum e_flag_type
  {
    F_PERCENT,
	F_INT,
	F_FLOAT,
	F_STR,
	F_CHAR,
	F_BOOL,
	F_PTR,
    NB_OF_FLAGS // always be at the end
  }			t_flag_type;

#endif  /*      __PRINTO_MACRO_H__    */