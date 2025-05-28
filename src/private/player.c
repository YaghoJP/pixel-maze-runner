#include "src/public/player.h"

GameObject player;

u16 PLAYER_init(u16 ind){
	ind += GAMEOBJECT_init(&player, &player_SPR, SCREEN_W/2-12, SCREEN_H/2-12, PAL_PLAYER, ind);
	player.health = PLAYER_HEALTH;
	return ind;
}

void PLAYER_update(){
    PLAYER_get_input_dir4();
    

}

static inline void PLAYER_get_input_dir4() {
	if (key_down(JOY_1, BUTTON_RIGHT)) {
		player.speed_x = PLAYER_SPEED;
		player.speed_y = 0;
		player.anim_sprite = 0;
	}
	else 
	if (key_down(JOY_1, BUTTON_LEFT)) {
		player.speed_x = -PLAYER_SPEED;
		player.speed_y = 0;
		player.anim_sprite = 4;
	}
	else
	if (key_down(JOY_1, BUTTON_UP)) {
		player.speed_x = 0;
		player.speed_y = -PLAYER_SPEED;
		player.anim_sprite = 2;
	}
	else
	if (key_down(JOY_1, BUTTON_DOWN)) {
		player.speed_x = 0;
		player.speed_y = PLAYER_SPEED;
		player.anim_sprite = 6;
	} 
}