/**
 ** @file init_tile_camera.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "tile.h"

void init_tile_camera(t_tile_camera *cam)
{
	cam->zoom_limits[0] = 3;
	cam->zoom_limits[1] = 9;
	cam->zoom = cam->zoom_limits[0];
	cam->tile_pos = SETPOS_ACC(0, 0);
}
