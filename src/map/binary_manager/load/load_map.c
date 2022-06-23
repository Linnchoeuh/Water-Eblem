/**
 ** @file load_map.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "map.h"

static int open_file(const char *file_path,
					 const char *file_name)
{
	int fd;
	bool end_with_slash;
	size_t i;
	char *full_path;

	full_path = term_strdup((char*) file_path);
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
	fd = open(full_path, O_RDONLY);
	bunny_free(full_path);
	return (fd);
}

t_map *load_map(const char *save_path,
				const char *file_name)
{
	int fd;
	t_map *map;

	fd = open_file(save_path, file_name);
	if (fd == -1)
	{
		fprinto(STDERR_FILENO,
			"Failed to open map file called : %s\n", file_name);
		return (NULL);
	}
	map = read_map_bin(fd);
	close(fd);
	if (map == NULL)
		fprinto(STDERR_FILENO,
			"Failed to read map file called : %s\n", file_name);
	return (map);
}