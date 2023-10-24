#ifndef DEFS_H
#define DEFS_H

#include <tonc.h>

#ifndef ISMAIN
    #define def
#else
    #define def extern
#endif

#define SCR_WID     240
#define CAM_X_TOL   32      // "Camera X Tolerance"
                            // How far player is allowed to be from the middle of the screen without the camera moving.

#define SCROLL_X    SCR_WID/2  // How far player must travel before the next map is loaded.

#define OAM_MAX     128     // Max amount of objects allowed.

typedef struct{
    u16 x, y;
}Vec2;

typedef struct{
    s16 x, y;
}Vec2s;

typedef struct{
    int x, y;
}Vec2i;

typedef struct{
    Vec2i pos;
    Vec2 scrPos;
    Vec2 mapPos;
    Vec2 size;
    Vec2s speed;
    u8 moveState;
    u8 oamID;
    u16 tileID;
    u8 dir;
}Player;
def Player player;

typedef struct{
    Vec2s offset;
    u16 curMapID;
}LevelInfo;
def LevelInfo levelInfo;

typedef struct{
    Vec2 pos;
    Vec2 size;
    u16 mapID;
}Trigger_MidLevelLoad;

#endif