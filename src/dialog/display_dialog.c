/**
 ** @file display_dialog.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "dialog.h"

#define BOX_HEIGHT 200
#define TEXT_MARGIN 20
#define ARROW_HEIGHT 10
#define ARROW_THICKNESS 5
#define ARROW_OFFSET ARROW_HEIGHT + ARROW_THICKNESS

static char *run_dialog(t_dialog *dialog,
						double delta_time,
						size_t str_size)
{

	if (dialog->char_pos < str_size)
	{
		dialog->char_pos += delta_time * dialog->char_par_sec;
		if (dialog->text_sound != NULL &&
			(long)dialog->prev_char_pos < (long)dialog->char_pos)
		{
			bunny_sound_set_cursor(&dialog->text_sound->sound, 0);
			bunny_sound_play(&dialog->text_sound->sound);
			dialog->prev_char_pos = dialog->char_pos;
		}
	}
	else
	{
		dialog->char_pos = str_size;
		dialog->ended = true;
	}
	return (term_strndup(dialog->msg, dialog->char_pos));
}

static void draw_arrow(t_bunny_buffer *buf)
{
	size_t i;
	t_bunny_position pos[2];
	unsigned int colors[2];

	colors[0] = PURPLE;
	colors[1] = PURPLE;
	i = 0;
	while (i < ARROW_THICKNESS)
	{
		pos[0].x = buf->width - TEXT_MARGIN;
		pos[0].y = buf->height - TEXT_MARGIN - ARROW_HEIGHT - i;
		pos[1] = SETPOS(pos[0].x - 20, pos[0].y + ARROW_HEIGHT);
		bunny_set_line(buf, pos, colors);
		pos[0] = SETPOS(pos[1].x - 20, pos[1].y - ARROW_HEIGHT);
		bunny_set_line(buf, pos, colors);
		i++;
	}
}

static void draw_dialog_box(t_bunny_buffer *buf,
							t_dialog *dialog,
							char *msg)
{
	int box_pos_y;
	t_bunny_area box;
	t_bunny_area msg_box;

	box_pos_y = buf->height - BOX_HEIGHT;
	draw_full_rect(buf, SETAREA(0, 0, buf->width, buf->height),
				   COLOR(64, 0, 0, 0));
	box = SETAREA(0, box_pos_y, buf->width, BOX_HEIGHT);
	msg_box = SETAREA(box.x + TEXT_MARGIN, box.y + TEXT_MARGIN,
					  box.w - TEXT_MARGIN * 2,
					  box.h - TEXT_MARGIN * 2 - ARROW_OFFSET);
	draw_full_rect(buf, box, COLOR(255, 255, 255, 230));
	dialog->font->color = BLACK;
	draw_str_in_box(buf, dialog->font, msg, msg_box);
	if (dialog->ended)
		draw_arrow(buf);
}

static bool interact_dialog_box(t_dialog *dialog,
								bool trigger,
								size_t str_size)
{
	if (trigger && dialog->char_pos < str_size && !dialog->ended)
		dialog->char_pos = str_size;
	if (trigger && dialog->ended)
	{
		if (dialog->valid_sound != NULL)
		{
			bunny_sound_set_cursor(&dialog->valid_sound->sound, 0);
			bunny_sound_play(&dialog->valid_sound->sound);
		}
		dialog->hide = true;
		return (true);
	}
	return (false);
}

bool display_dialog(t_bunny_buffer *buf,
					t_dialog *dialog,
					bool trigger,
					double delta_time)
{
	char *msg;
	size_t str_size;

	if (dialog->hide)
		return (true);
	str_size = term_strlen(dialog->msg);
	msg = run_dialog(dialog, delta_time, str_size);
	draw_dialog_box(buf, dialog, msg);
	bunny_free(msg);
	return (interact_dialog_box(dialog, trigger, str_size));
}