/**
 ** @file delete_conv.c
 ** @author Yann Lebib [lebib.yann@gmail.com]
 ** @brief
 **/

#include	"dialog.h"

void		delete_conv(t_conv	*conv)
{
  unsigned int	i;

  if (conv == NULL)
    return;
  i = 0;
  while (i != conv->nbr_dialog)
    {
      free(conv->dialog[i].msg);
      i++;
    }
  free(conv->dialog);
  free(conv);
}

