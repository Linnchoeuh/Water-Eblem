/**
 ** @file display_entity.h
 ** @author Jeanpierre Janopoulos [jpj220603@gmail.com]
 ** @brief
 **/

#include "map_struct.h"
#include "animation.h"

void display_entity(t_bunny_buffer *buf,
				    t_entity *entity,
				    t_bunny_area area)
{
    uint16_t i;

	if (entity->animation == NULL)
		return;
	i = 0;
	(void)i;
	display_animation(buf, entity->animation, area);
	// while (entity->animation[i] != NULL)
	// {
	// 	display_animation(buf, entity->animation[i], area);
	// 	i++;
	// }
}

