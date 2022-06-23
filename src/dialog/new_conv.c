/**
 ** @file new_conv.c
 ** @author Yann Lebib [lebib.yann@gmail.com]
 ** @brief
 **/

#include	"dialog.h"

t_conv		*new_conv(void)
{
  t_conv	*conv;

  if ((conv = malloc(sizeof(t_conv))) == NULL)
    return (NULL);
  conv->dialog = NULL;
  conv->nbr_dialog = 0;
  conv->current_dialog = 0;
  conv->hide = false;
  return (conv);
}
