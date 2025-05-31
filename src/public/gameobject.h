#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include <genesis.h>
#include "resources.h"
#include "globals.h"
#include "sprite_eng.h"

//Estrutura principal de qualquer "Objeto" no projeto.
typedef struct 
{

    Sprite *sprite;
    fix16 pos_x;
    f16 pos_y;
    f16 next_pos_x;
    f16 next_pos_y;
    f16 speed_x;
    f16 speed_y;
    u8 width;
    u8 height;
    u8 anim_sprite;
    u8 health;
    
} GameObject;

//"Método construtor".
u16 GAMEOBJECT_init(GameObject* const obj, const SpriteDefinition* const sprite, s16 x, s16 y, u8 pal , u16 ind);

#endif