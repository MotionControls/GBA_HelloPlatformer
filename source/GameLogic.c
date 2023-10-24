#include "GameLogic.h"

int Init(OBJ_ATTR* oamArr){
    player = (Player){
        .pos = {SCR_WID/2,0},
        .scrPos = {SCR_WID/2,0},
        .mapPos = {0,0},
        .size = {16,16},
        .speed = {0,0},
        .moveState = 0,
        .oamID = 0,
        .tileID = 0,
        .dir = 0
    };

    InitSprite(player.tileID, Sprite_Timmy_TempTiles, Sprite_Timmy_TempTilesLen, Sprite_Timmy_TempPal, Sprite_Timmy_TempPalLen);
    obj_set_attr(&oamArr[player.oamID], player.pos.y, ATTR1_SIZE_16 | player.pos.x, player.tileID);

    levelInfo = (LevelInfo){
        .offset = {0,0},
        .curMapID = 0
    };

    InitBackground(Map_TestTiles, Map_TestTilesLen, Map_TestPal, Map_TestPalLen, Map_TestMap, Map_TestMapLen);
    REG_BG0CNT = BG_SIZE0 | (30 << 8) | BG_4BPP;

    return 0;
}

int Step(OBJ_ATTR* oamArr){
    // Get Input, Update speed and direction.
    player.speed.x = key_tri_horz() * 2;
    if(player.speed.x > 0)
        player.dir = 0;
    else if(player.speed.x < 0)
        player.dir = 1;

    // Apply speed to position.
    player.pos.x += player.speed.x;
    
    // Adjust Level Offset
    if((player.pos.x % SCR_WID) < (SCR_WID/2) - CAM_X_TOL)
        levelInfo.offset.x -= player.speed.x;
    if((player.pos.x % SCR_WID) > (SCR_WID/2) + CAM_X_TOL)
        levelInfo.offset.x += player.speed.x;
    
    player.scrPos.x = player.pos.x;

    if(player.pos.x >= SCROLL_X+32){
        InitBackground(Map_Test_0_0_5Tiles, Map_Test_0_0_5TilesLen, Map_Test_0_0_5Pal, Map_TestPalLen, Map_Test_0_0_5Map, Map_Test_0_0_5MapLen);
        levelInfo.offset.x = 0;
    }

    UpdateOAM(oamArr);
    return 0;
}

void UpdateOAM(OBJ_ATTR* oamArr){
    obj_set_attr(&oamArr[player.oamID], player.scrPos.y, ATTR1_SIZE_16 | (player.dir << 12) | player.scrPos.x, player.tileID);
    REG_BG0HOFS = levelInfo.offset.x;
}