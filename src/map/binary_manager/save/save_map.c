/**
 ** @file save_map.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "map.h"

static int init_map_file(const char *save_path,
						 const char *file_name)
{
	int fd;
	bool end_with_slash;
	size_t i;
	char *full_path;

	full_path = term_strdup((char*) save_path);
	if (full_path == NULL)
		return (-1);
	i = 0;
	end_with_slash = false;
	while (full_path[i] != '\0')
	{
		end_with_slash = (full_path[i] == '/');
		i++;
	}
	if (!end_with_slash)
		term_str_append(&full_path, "/");
	term_str_append(&full_path, (char*) file_name);
	term_str_append(&full_path, ".map");
	fd = open(full_path, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	bunny_free(full_path);
	return (fd);
}

bool save_map(t_map *map,
			  const char *save_path,
			  const char *file_name)
{
	int fd;

	fd = init_map_file(save_path, file_name);
	if (fd == -1)
	{
		fprinto(STDERR_FILENO,
			"Failed to create save file called : %s\n", file_name);
		return (false);
	}
	if (!write_map_bin(fd, map))
	{
		close(fd);
		fprinto(STDERR_FILENO,
			"Failed to write save file called : %s\n", file_name);
		return (false);
	}
	close(fd);
	return (true);
}