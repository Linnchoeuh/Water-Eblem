/**
 ** @file move_tile_camera.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "tile.h"

void move_tile_camera(t_tile_camera *cam,
					  t_key_input *key_input,
					  double delta_time)
{
	double cam_zoom_move;

	cam->tile_pos.x += key_input->lstick_hor * 0.1 * delta_time;
	cam->tile_pos.y += key_input->lstick_ver * 0.1 * delta_time;
	if (key_input->left_arrow || key_input->right_arrow ||
		key_input->down_arrow || key_input->up_arrow)
	{
		cam->tile_pos = SETPOS_ACC(ROUND_NUM(cam->tile_pos.x),
								   ROUND_NUM(cam->tile_pos.y));
		cam->tile_pos.x += key_input->right_arrow - key_input->left_arrow;
		cam->tile_pos.y += key_input->down_arrow - key_input->up_arrow;
	}
	cam_zoom_move = (cam->zoom_limits[1] - cam->zoom_limits[0]) / 2;
	if (key_input->pg_up)
		cam->zoom += cam_zoom_move;
	else if (key_input->pg_down)
		cam->zoom -= cam_zoom_move;
	if (cam->zoom > cam->zoom_limits[1])
		cam->zoom = cam->zoom_limits[1];
	if (cam->zoom < cam->zoom_limits[0])
		cam->zoom = cam->zoom_limits[0];
}