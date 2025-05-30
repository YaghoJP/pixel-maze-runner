#include <genesis.h>
#include "sprite_eng.h"
#include "public/gameobject.h"
#include "public/globals.h"

u16 GAMEOBJECT_init(GameObject* const obj, const SpriteDefinition* const sprite, s16 x, s16 y, u8 pal , u16 ind){

    obj->pos_x = x;
    obj->pos_y = y;
    obj->next_pos_x = obj->pos_x;
    obj->next_pos_y = obj->pos_y;
    obj->speed_x = 0;
    obj->speed_y = 0;
    PAL_setPalette(pal, sprite->palette->data, DMA);
    obj->sprite = SPR_addSprite(sprite, x, y, pal);
    obj->width = obj->sprite->definition->w;
    obj->height = obj->sprite->definition->h;

    return obj->sprite->definition->maxNumTile;
}
