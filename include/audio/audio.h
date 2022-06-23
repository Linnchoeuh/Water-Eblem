/**
 ** @file audio.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __AUDIO_H__
#define __AUDIO_H__

#include <lapin.h>

#include "audio_struct.h"
#include "file_manager.h"
#include "terminal_strsplit.h"

t_bunny_music **load_audio_from_dir(char *path,
									 size_t *nbr_of_audio,
									 bool enable_loop);

void switch_music(t_audio *audio,
				  t_bunny_music *music_to_play);

void update_volume(t_audio *audio);

#endif