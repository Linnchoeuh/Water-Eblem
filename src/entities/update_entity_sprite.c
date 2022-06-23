/**
 ** @file update_entity_sprite.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "entities.h"

void update_entity_sprite(t_entity *entity,
						  t_sprite_bank *entities_asset)
{
	t_entity n_entity;
	t_sprite *entity_asset;
	int team;
	int pos;

	pos = entity->class + (entity->team * TOTAL_ENTITY_CLASS);
	entity_asset = entities_asset->sprites[pos];
	team = entity->team;
	n_entity = new_entity(new_animation_struct(entity_asset),
						  entity->class, entity->pos);
	n_entity.team = team;
	delete_entity(entity);
	*entity = n_entity;
}