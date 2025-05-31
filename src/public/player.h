#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <genesis.h>
#include "gameobject.h"
#include "resources.h"
#include "globals.h"
#include "utils.h"

#define ANIM_RIGTH 0
#define ANIM_LEFT 2
#define ANIM_UP 1
#define ANIM_DOWN 3
#define ANIM_SHOOT_RIGTH 4
#define ANIM_SHOOT_LEFT 5
#define ANIM_SHOOT_RIGTH 6
#define ANIM_SHOOT_LEFT 7

#define PLAYER_HEALTH 5
#define PLAYER_SPEED FIX16(2)
#define PLAYER_SPEED45 FIX16(0.707 * 2)

extern GameObject player;

u16 PLAYER_init(u16 ind);

void PLAYER_update();

#endif