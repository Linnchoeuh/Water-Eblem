/**
 ** @file font_struct.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __FONT_STRUCT_H__
#define __FONT_STRUCT_H__

#define FONT_PATH "./asset/font/project.ttf"

#define FONT_RATIO 0.58

typedef enum	e_font_size
{
	FS_15,
	FS_20,
	FS_30,
	FS_40,
	FS_50,
	FS_100,
	FS_150,
	FS_TOTAL
}				t_font_size;

#endif