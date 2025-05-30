#include "public/background.h"

u16 BACKGROUND_init(u16 ind){

   PAL_setPalette(PAL_BACKGROUND, bg_1.palette->data, DMA);
   VDP_drawImageEx(BG_BACKGROUND, &bg_1, TILE_ATTR_FULL(PAL_BACKGROUND, 0, 0, 0, ind), 0, 0, TRUE, DMA);

   return bg_1.tileset->numTile;
}