#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <genesis.h>
#include "gameobject.h"
#include "res/resources.h"
#include "globals.h"

#define PLAYER_HEALTH 5
#define PLAYER_SPEED FIX16(2)

extern GameObject player;

u16 PLAYER_init(u16 ind);

void PLAYER_update();

#endif