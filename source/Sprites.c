#include "Sprites.h"

void InitSprite(int scrBlock, const u16* tiles, int tLen, const u16* pal, int pLen){
    memcpy16(&tile_mem[4][scrBlock], tiles, tLen/2);    // Tiles
	memcpy16(pal_obj_mem, pal, pLen/2);         		// Palette
}

void InitBackground(const u16* tiles, int tLen, const u16* pal, int pLen, const u16* map, int mLen){
    memcpy16(&tile_mem[0][0], tiles, tLen/2);	// Tiles
	memcpy16(pal_bg_mem, pal, pLen/2);      	// Palette
	memcpy16(&se_mem[30][0], map, mLen/2);  	// Map
}