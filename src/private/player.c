#include "public/player.h"

GameObject player;

static inline void PLAYER_get_input_dir4();
static inline void PLAYER_get_input_gun();
static inline void PLAYER_get_input_dir8();

int timer = 0;

u16 PLAYER_init(u16 ind){
	ind += GAMEOBJECT_init(&player, &player_SPR, SCREEN_W/2-12, SCREEN_H/2-12, PAL_PLAYER, ind);
	player.health = PLAYER_HEALTH;
	return ind;
}

void PLAYER_update(){

	//PLAYER_get_input_dir8();
	//PLAYER_get_input_gun();
   // player.next_pos_x = player.pos_x + player.speed_x;
	//player.next_pos_y = player.pos_y + player.speed_y;

	if(key_down(JOY_1, BUTTON_RIGHT))
	{
		//player.next_pos_x = player.pos_x + FIX16(1);
		player.pos_x +=  fix16Mul(FIX16(0.4), FIX16(0.05)); //player.next_pos_x;
	}

	SPR_setPosition(player.sprite, player.pos_x, player.pos_y);
	//SPR_setAnim(player.sprite, player.anim_sprite);
}

static inline void PLAYER_get_input_dir4() {
	player.speed_x = 0;
	player.speed_y = 0;

	if (key_down(JOY_1, BUTTON_RIGHT)) {
		player.speed_x = PLAYER_SPEED;
		player.speed_y = 0;
		player.anim_sprite = ANIM_RIGTH;
	}
	else 
	if (key_down(JOY_1, BUTTON_LEFT)) {
		player.speed_x = -PLAYER_SPEED;
		player.speed_y = 0;
		player.anim_sprite = ANIM_LEFT;
	}
	else
	if (key_down(JOY_1, BUTTON_UP)) {
		player.speed_x = 0;
		player.speed_y = -PLAYER_SPEED;
		player.anim_sprite = ANIM_UP;
	}
	else
	if (key_down(JOY_1, BUTTON_DOWN)) {
		player.speed_x = 0;
		player.speed_y = PLAYER_SPEED;
		player.anim_sprite = ANIM_DOWN;
	} 
}

static inline void PLAYER_get_input_gun() {

	u16 button = JOY_readJoypad(JOY_1);

	if (button & BUTTON_B) {

		player.speed_x = PLAYER_SPEED;
		player.speed_y = 0;
		player.anim_sprite = ANIM_RIGTH;
	}

}

static inline void PLAYER_get_input_dir8() {
	player.speed_x = 0;
	player.speed_y = 0;

	/* ANIM DIRECTIONS
		      2
		   3     1
		4           0
		   5     7
		      6
	*/

	if (key_down(JOY_1, BUTTON_RIGHT)) {
		player.speed_x = PLAYER_SPEED;
		player.anim_sprite = 0;

		if (key_down(JOY_1, BUTTON_UP)) {
			player.speed_x =  PLAYER_SPEED45;
			player.speed_y = -PLAYER_SPEED45;
			player.anim_sprite = 0;
			return;
		} 
		else
		if (key_down(JOY_1, BUTTON_DOWN)) {
			player.speed_x =  PLAYER_SPEED45;
			player.speed_y =  PLAYER_SPEED45;
			player.anim_sprite = 0;
			return;
		}
	} 
	else 
	if (key_down(JOY_1, BUTTON_LEFT)) {
		player.speed_x = -PLAYER_SPEED;
		player.anim_sprite = 0;

		if (key_down(JOY_1, BUTTON_UP)) {
			player.speed_x = -PLAYER_SPEED45;
			player.speed_y = -PLAYER_SPEED45;
			player.anim_sprite = 0;
			return;
		}
		else
		if (key_down(JOY_1, BUTTON_DOWN)) {
			player.speed_x = -PLAYER_SPEED45;
			player.speed_y =  PLAYER_SPEED45;
			player.anim_sprite = 0;
			return;
		}
	}

	if (key_down(JOY_1, BUTTON_UP)) {
		player.speed_y = -PLAYER_SPEED;
		player.anim_sprite = 0;
	}
	else
	if (key_down(JOY_1, BUTTON_DOWN)) {
		player.speed_y = PLAYER_SPEED;
		player.anim_sprite = 0;
	} 
}
