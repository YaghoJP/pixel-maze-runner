#include "public/player.h"

GameObject player;

static inline void PLAYER_get_input_dir4();

u16 PLAYER_init(u16 ind){
	ind += GAMEOBJECT_init(&player, &player_SPR, SCREEN_W/2-12, SCREEN_H/2-12, PAL_PLAYER, ind);
	player.health = PLAYER_HEALTH;
	return ind;
}

void PLAYER_update(){
    
	PLAYER_get_input_dir4();

    player.next_pos_x = player.pos_x + player.speed_x;
	player.next_pos_y = player.pos_y + player.speed_y;

	// check and resolve walls
	//LEVEL_move_and_slide(&player);
	
	// update current position
	player.pos_x = player.next_pos_x;
	player.pos_y = player.next_pos_y;

	SPR_setPosition(player.sprite, player.pos_x, player.pos_y);
	SPR_setAnim(player.sprite, player.anim_sprite);
}

static inline void PLAYER_get_input_dir4() {

	u16 button = JOY_readJoypad(JOY_1);

	if (button & BUTTON_RIGHT) {
		kprintf("Direita");

		player.speed_x = PLAYER_SPEED;
		player.speed_y = 0;
		player.anim_sprite = ANIM_RIGTH;
	}
	else 
	if (button & BUTTON_LEFT) {
		kprintf("Esquerda");

		player.speed_x = -PLAYER_SPEED;
		player.speed_y = 0;
		player.anim_sprite = ANIM_LEFT;
	}
	else
	if (button & BUTTON_UP) {
		player.speed_x = 0;
		player.speed_y = -PLAYER_SPEED;
		player.anim_sprite = ANIM_UP;
	}
	else
	if (button & BUTTON_DOWN) {
		player.speed_x = 0;
		player.speed_y = PLAYER_SPEED;
		player.anim_sprite = ANIM_DOWN;
	} 
}