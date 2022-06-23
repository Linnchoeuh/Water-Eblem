/**
 ** @file add_dialog.c
 ** @author Yann Lebib [lebib.yann@gmail.com]
 ** @brief
 **/

#include	"dialog.h"

bool		add_dialog(t_conv	*conv,
			   t_dialog	new_dialog)
{
  conv->dialog = std_realloc(conv->dialog, (conv->nbr_dialog + 1) * sizeof(t_dialog));
  if (conv->dialog == NULL)
    return (false);
  conv->dialog[conv->nbr_dialog] = new_dialog;
  conv->nbr_dialog++;
  return (true);
}
