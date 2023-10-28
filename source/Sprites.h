#ifndef SPRITES_H
#define SPRITES_H

#include <tonc.h>
#include "string.h"

#include "sprites/S_Player_Idle.h"
#include "sprites/S_Player_Run.h"
#include "sprites/S_Player_Skid.h"

void InitSprite(int spriteBank, const u16* tiles, int tilesLen, const u16* palette, int paletteLen);
void InitBackground(const u16* tiles, int tilesLen, const u16* pal, int palLen, const u16* map, int mapLen);

#endif