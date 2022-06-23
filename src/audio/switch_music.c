/**
 ** @file switch_music.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "audio.h"

void switch_music(t_audio *audio,
				  t_bunny_music *music_to_play)
{
	if (audio->played_music != music_to_play)
	{
		if (audio->played_music != NULL)
			bunny_sound_stop(&audio->played_music->sound);
		audio->played_music = music_to_play;
		bunny_sound_set_cursor(&audio->played_music->sound, 0);
	}
	if (!bunny_sound_is_playing(&audio->played_music->sound))
		bunny_sound_play(&audio->played_music->sound);
}