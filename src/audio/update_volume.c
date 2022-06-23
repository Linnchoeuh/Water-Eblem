/**
 ** @file update_volume.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "audio.h"

void update_volume(t_audio *audio)
{
	size_t i;
	double sfx_vol;
	double music_vol;

	sfx_vol = (audio->master_vol * audio->sfx_vol) / 100;
	music_vol = (audio->master_vol * audio->music_vol) / 100;
	i = 0;
	while (i < audio->nbr_sfx)
	{
		bunny_sound_volume(&audio->sfx[i]->sound, sfx_vol);
		i++;
	}
	i = 0;
	while (i < audio->nbr_music)
	{
		bunny_sound_volume(&audio->music[i]->sound, music_vol);
		i++;
	}
}