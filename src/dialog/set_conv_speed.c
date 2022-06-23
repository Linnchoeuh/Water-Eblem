/**
 ** @file set_conv_speed.c
 ** @author Yann Lebib [yann.lebib@gmail.com]
 ** @brief
 **/

#include	"dialog.h"

void		set_conv_speed(t_conv	*conv,
			       double	char_par_sec)
{
  unsigned int	i;

  i = 0;
  while (i != conv->nbr_dialog)
    {
      set_dialog_speed(&conv->dialog[i], char_par_sec);
      i++;
    }
}

