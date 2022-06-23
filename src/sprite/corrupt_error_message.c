/**
 ** @file corrupt_error_message.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "sprite.h"

bool corrupt_error_message(t_sprite *sprite,
						   char *file_name)
{
	delete_sprite_struct(sprite);
	if (file_name != NULL)
		fprinto(STDERR_FILENO,
			"Sprite Loader: %s is corrupted.\n", file_name);
	return (false);
}