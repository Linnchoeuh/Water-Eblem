/**
 ** @file sprite.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __SPRITE_H__
#define __SPRITE_H__

#include <stdlib.h>
#include <lapin.h>
#include <fcntl.h>
#include <stdbool.h>
#include <printo.h>


#include "bunny_macro.h"
#include "libstd.h"
#include "file_manager.h"
#include "sprite_struct.h"
#include "tile.h"

t_sprite *new_sprite_struct(void);

void delete_sprite_struct(t_sprite *sprite);

void print_sprite_struct(t_sprite *sprite);



t_sprite *load_sprite(char *file_name);

t_sprite *read_sprite_bin(int fd);

bool read_sprite_bin_header(int fd,
							t_sprite *sprite);

bool read_sprite_bin_image(int fd,
					   t_sprite *sprite);

bool corrupt_error_message(t_sprite *sprite,
						   char *file_name);



bool write_sprite_bin(int fd,
					  t_sprite *sprite);

bool write_sprite_bin_header(int fd,
							 t_sprite *sprite);

bool write_sprite_bin_image(int fd,
							t_sprite *sprite);



t_sprite_bank *load_sprite_from_dir(char *folder_path);

size_t sprite_bank_size(t_sprite_bank *bank);

bool sprite_bank_append(t_sprite_bank *dest_bank,
						t_sprite_bank *src_bank);

bool sprite_bank_add_sprite(t_sprite_bank *bank,
							t_sprite *new_sprite);

t_sprite_bank *new_sprite_bank(void);

void delete_sprite_bank(t_sprite_bank *bank);

#endif