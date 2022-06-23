/**
 ** @file list_file.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "file_manager.h"

static void sort_file_list(char **file_list)
{
	size_t i;
	size_t k;

	i = 0;
	while (file_list[i] != NULL)
	{
		k = i + 1;
		while (file_list[k] != NULL)
		{
			if (term_strcmp(file_list[i], file_list[k]) < 0)
				term_split_swap_str(file_list, i, k);
			k++;
		}
		i++;
	}
}

static char *generate_path(char *file_name,
						   char *path,
						   bool include_path)
{
	size_t i;
	bool have_a_slash;

	if (include_path)
	{
		i = 0;
		have_a_slash = false;
		while (path[i] != '\0')
		{
			have_a_slash = (path[i] == '/');
			i++;
		}
		if (have_a_slash)
			return (generate_str("%s%s", path, file_name));
		return (generate_str("%s/%s", path, file_name));
	}
	return (generate_str("%s", file_name));
}

static char **get_list(DIR *dir,
					   char *path,
					   bool include_path)
{
	char **file_list;
	char *tmp_str;
	struct dirent *dir_data;

	file_list = bunny_malloc(sizeof(char *));
	if (file_list == NULL)
		return (NULL);
	file_list[0] = NULL;
	while ((dir_data = readdir(dir)) != NULL)
	{
		if (term_strcmp(dir_data->d_name, ".") != 0 &&
			term_strcmp(dir_data->d_name, "..") != 0)
		{
			tmp_str = generate_path(dir_data->d_name, path, include_path);
			if (tmp_str == NULL ||
				!term_split_insert(&file_list, tmp_str, -1))
			{
				term_split_free(file_list);
				if (tmp_str != NULL)
					bunny_free(tmp_str);
				return (NULL);
			}
			bunny_free(tmp_str);
		}
	}
	return (file_list);
}

char **list_file(char *path,
				 bool include_path,
				 bool sort)
{
	DIR *dir;
	char **file_list;

	dir = opendir(path);
	if (dir == NULL)
		return (NULL);
	file_list = get_list(dir, path, include_path);
	if (sort)
		sort_file_list(file_list);
	// term_split_print(file_list, "\n");
	closedir(dir);
	return (file_list);
}