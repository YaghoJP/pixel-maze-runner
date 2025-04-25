//Includes necessários
#include <genesis.h>
#include <sprite_eng.h>

void game_init()
{

  SYS_disableInts();
  VDP_setScreenHeight224();
  VDP_setScreenWidth320();

  SPR_init();

  
  SYS_enableInts();
}

int main(bool resetType)
{

  if(!resetType)
  {
    SYS_hardReset();
  }
  
  game_init();

  VDP_drawText("OLA", 10, 10);

  while(true)
  {

    //atualiza o hardware da tabela de sprites
    SPR_update();

    //espera o VBLANK
    SYS_doVBlankProcess();

  }

  return(0);
}
