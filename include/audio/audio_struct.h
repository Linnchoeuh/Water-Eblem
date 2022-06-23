/**
 ** @file audio_struct.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __AUDIO_STRUCT_H__
#define __AUDIO_STRUCT_H__

#include <lapin.h>

typedef enum	e_music
{
	MU_EDITOR,
	MU_PLAY,
	MU_MAIN
}				t_music;

typedef enum	e_sfx
{
	SFX_BACK1,
	SFX_CHANGE_TURN1,
	SFX_CHANGE_TURN2,
	SFX_CRIT1,
	SFX_CRIT2,
	SFX_DIALOG,
	SFX_HIT1,
	SFX_HIT2,
	SFX_ITEM_OBTAIN,
	SFX_LEVEL_UP,
	SFX_MAGIC,
	SFX_MAP_MOVE,
	SFX_MISS,
	SFX_SELECT_UNIT,
	SFX_STEP,
	SFX_VALIDATE,
	SFX_VALIDATE_DIALOG,
	SFX_XP
}				t_sfx;

typedef struct	s_audio
{
	t_bunny_music **music;
	t_bunny_music *played_music;
	double master_vol;
	size_t nbr_music;
	double music_vol;
	t_bunny_music **sfx;
	size_t nbr_sfx;
	double sfx_vol;
}				t_audio;

#endif