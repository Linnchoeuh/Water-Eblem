/**
 ** @file file_manager.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __FILE_MANAGER_H__
#define __FILE_MANAGER_H__

#include <lapin.h>
#include <dirent.h>
#include <printo.h>

#include "libstd.h"
#include "terminal_strsplit.h"

char **list_file(char *path,
				 bool include_path,
				 bool sort);

#endif
