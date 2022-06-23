/**
 ** @file reset_conv.c
 ** @author Yann Lebib [lebib.yann@gmail.com]
 ** @brief
 **/

#include	"dialog.h"

void		reset_conv_status(t_conv	*conv)
{
  unsigned int	i;

  i = 0;
  
  while (i != conv->nbr_dialog)
    {
      reset_dialog_status(&(conv->dialog[i]));
      i++;
    }
  conv->current_dialog = 0;
  conv->hide = false;
}

