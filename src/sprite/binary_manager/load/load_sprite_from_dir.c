/**
 ** @file load_sprite_from_dir.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "sprite.h"

t_sprite_bank *load_sprite_from_dir(char *folder_path)
{
	size_t i;
	char **files;
	t_sprite *tmp_sprite;
	t_sprite_bank *bank;

	files = list_file(folder_path, true, true);
	if (files == NULL)
		return (NULL);
	bank = new_sprite_bank();
	if (bank == NULL)
	{
		term_split_free(files);
		return (NULL);
	}
	i = 0;
	while (files[i] != NULL)
	{
		tmp_sprite = load_sprite(files[i]);
		if (tmp_sprite != NULL)
			sprite_bank_add_sprite(bank, tmp_sprite);
		i++;
	}
	return (bank);
}