/**
 ** @file play_animation.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "animation.h"

void play_animation(t_animation *anim,
					t_bunny_time time)
{
	double *delay;
	double current_duration;
	t_bunny_time time_passed;

	if (anim->sprite == NULL ||
		anim->sprite->duration <= 0 ||
		anim->sprite->nbr_of_frame <= 1)
		return;
	if (!anim->is_playing)
		anim->time_in_ns = bunny_get_time();
	anim->is_playing = true;
	if (time == 0)
		time = bunny_get_time();
	time_passed = 0;
	if (anim->time_in_ns < time)
		time_passed = time - anim->time_in_ns;
	anim->time_elapsed += CONVERT_NS_TO_SECOND(time_passed);
	while (anim->time_elapsed > anim->sprite->duration)
		anim->time_elapsed -= anim->sprite->duration;
	anim->curr_frame = 0;
	current_duration = 0;
	delay = anim->sprite->frame_delay;
	while (current_duration + delay[anim->curr_frame] < anim->time_elapsed)
	{
		current_duration += delay[anim->curr_frame];
		anim->curr_frame++;
	}
	anim->time_in_ns = time;
}