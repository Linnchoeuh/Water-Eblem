/**
 ** @file display_conv.c
 ** @author Yann Lebib [lebib.yann@gmail.com]
 ** @brief
 **/

#include	"dialog.h"

bool		display_conv(t_bunny_buffer	*buf,
			     t_conv		*conv,
			     bool		trigger,
			     double		delta_time)
{
  if (conv->hide == true)
    return (true);
  if (display_dialog(buf, &conv->dialog[conv->current_dialog], trigger, delta_time))
    {
      conv->current_dialog++;
      if (conv->current_dialog == conv->nbr_dialog)
	conv->hide = true;
    }
  return (false);
}

