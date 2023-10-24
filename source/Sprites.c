#include "Sprites.h"

void InitSprite(int sb, const u16* t, int tL, const u16* p, int pL){
    memcpy16(&tile_mem[4][sb], t, tL/2);    // Tiles
	memcpy16(pal_obj_mem, p, pL/2);         // Palette
}

void InitBackground(const u16* t, int tL, const u16* p, int pL, const u16* m, int mL){
    memcpy16(&tile_mem[0][0], t, tL/2); // Tiles
	memcpy16(pal_bg_mem, p, pL/2);      // Palette
	memcpy16(&se_mem[30][0], m, mL/2);  // Map
}