/**
 ** @file create_map_list.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "map.h"

t_map_list *create_map_list(char *path)
{
	int fd;
	size_t i;
    char **list;
	char *map_name;
	char **tmp;
	t_map_elem *elem;
	t_map_list *map_list;
	t_bunny_position map_size;

	map_list = bunny_malloc(sizeof(t_map_list));
	if (map_list == NULL)
		return (NULL);
	map_list->elem = NULL;
	map_list->disable_buttons = false;
	list = list_file(path, true, true);
	i = 0;
	while (list[i] != NULL)
	{
		fd = open(list[i], O_RDONLY);
		if (fd != -1)
		{
			if (read_map_bin_header(fd, &map_size))
			{
        		map_name = term_strdup(term_strrchr(list[i], '/'));
				tmp = term_split_str(&map_name[1], '.');
				free(map_name);
				map_name = term_strdup(tmp[0]);
				term_split_free(tmp);
				elem = new_map_elem(map_name, term_strdup(path), map_size);
				add_map_elem(map_list, elem);
			}
			close(fd);
		}
		i++;
	}
	return (map_list);
}