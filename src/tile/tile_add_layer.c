/**
 ** @file tile_add_layer.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "tile.h"

bool tile_add_layer(t_tile *tile,
					t_sprite *layer)
{
	size_t size;
	t_animation *anim;
	t_animation **new_layers;

	if (layer == NULL)
		return (false);
	anim = new_animation_struct(layer);
	if (anim == NULL)
		return (false);
	size = count_tile_layers(tile);
	new_layers = bunny_malloc((size + 2) * sizeof(t_animation*));
	if (new_layers == NULL)
	{
		delete_animation_struct(anim);
		return (false);
	}
	std_memcpy(new_layers, tile->layers, size * sizeof(t_sprite*));
	new_layers[size] = anim;
	new_layers[size + 1] = NULL;
	bunny_free(tile->layers);
	tile->layers = new_layers;
	return (true);
}