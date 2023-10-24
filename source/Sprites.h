#ifndef SPRITES_H
#define SPRITES_H

#include <tonc.h>
#include "string.h"

#include "sprites/maps/Level.h"

#include "sprites/maps/Level_0_0.h"
#include "sprites/maps/Level_1_0.h"
#include "sprites/maps/Level_2_0.h"
#include "sprites/maps/Level_3_0.h"

#include "sprites/maps/Level_0_1.h"
#include "sprites/maps/Level_1_1.h"
#include "sprites/maps/Level_2_1.h"


void InitSprite(int spriteBank, const u16* tiles, int tilesLen, const u16* palette, int paletteLen);
void InitBackground(const u16* tiles, int tilesLen, const u16* pal, int palLen, const u16* map, int mapLen);

#endif