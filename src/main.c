//Includes necessários
#include <genesis.h>
#include "sprite_eng.h"
#include "resources.h"
#include "public/background.h"
#include "public/player.h"


u16 ind = TILE_USER_INDEX;

void game_init()
{
  VDP_setScreenWidth320();
  SPR_init();

  ind = BACKGROUND_init(ind);

  ind = PLAYER_init(ind);
}

void game_update()
{
  PLAYER_update();
}

int main(bool resetType)
{

  if(!resetType)
  {
    SYS_hardReset();
  }

  SYS_showFrameLoad(true);
	game_init();

	SYS_doVBlankProcess();

  while(true)
  {
    update_input();
    game_update();


    //atualiza o hardware da tabela de sprites
    SPR_update();

    //espera o VBLANK
    SYS_doVBlankProcess();
    //VDP_waitVSync();
  }

  return(0);
}
