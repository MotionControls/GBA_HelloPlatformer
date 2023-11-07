#ifndef DEFS_H
#define DEFS_H

#include <tonc.h>
#include "Sprites.h"

#ifdef ISMAIN
    #define def
#else
    #define def extern
#endif

#define OAM_MAX     128     // Max amount of objects allowed.
#define SCR_WID     240
#define SCR_HGT     160

typedef struct O_WARDEN{
    OBJ_ATTR oamArray[OAM_MAX];
    int oamCount;
    int curLevel, curScreen, maxScreen;
    int camx, camy;
    int tolxMin, tolxMax;               // How far from the middle of the screen player has to be to scroll.
}O_WARDEN;
def O_WARDEN Warden;

typedef struct O_LEVEL{
    int eid;                            // Effect ID (Wind, Ice, etc.)
}O_LEVEL;
def O_LEVEL Level;

typedef struct{
    u16 x,y;
}Vec2u;

typedef struct{
    s16 x,y;
}Vec2s;

typedef struct{
    u16 x,y,w,h;
}Rect;

typedef struct O_PLAYER{
    u16 tid, oid;
    float x,y;
    Rect rect;
    float xs,ys;
    int lastDir;
}O_PLAYER;
def O_PLAYER Player;

#endif