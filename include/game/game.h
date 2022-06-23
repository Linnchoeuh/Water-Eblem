/**
 ** @file game.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __GAME_H__
#define __GAME_H__

#include <lapin.h>

#include "game_struct.h"
#include "framerate.h"
#include "keyboard.h"
#include "audio.h"
#include "map.h"

t_game *game_struct_setup(int width,
						  int height,
						  unsigned int max_fps);

void game_struct_delete(t_game *game);

#endif