/**
 ** @file load_audio_from_dir.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "audio.h"

t_bunny_music **load_audio_from_dir(char *path,
									 size_t *nbr_of_audio,
									 bool enable_loop)
{
	size_t i;
	char **file_list;
	size_t tmp_nbr_of_audio;
	t_bunny_music **audio;

	file_list = list_file(path, true, true);
	if (file_list == NULL)
		return (NULL);
	tmp_nbr_of_audio = term_split_len(file_list);
	audio = bunny_malloc(tmp_nbr_of_audio * sizeof(t_bunny_effect *));
	if (audio == NULL)
	{
		term_split_free(file_list);
		return (NULL);
	}
	i = 0;
	while (i < tmp_nbr_of_audio)
	{
		audio[i] = bunny_load_music(file_list[i]);
		if (audio[i] != NULL)
		{
			bunny_sound_loop(&audio[i]->sound, enable_loop);
			bunny_sound_volume(&audio[i]->sound, 100);
		}
		i++;
	}
	(*nbr_of_audio) = tmp_nbr_of_audio;
	return (audio);
}