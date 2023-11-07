#include "Logic.h"

void InitLogic(){
    oam_init(Warden.oamArray, OAM_MAX);
    
    Warden = (O_WARDEN){
        .oamCount = 0,
        .curLevel = 0,
    };
    InitBackground(Level_0Tiles, Level_0TilesLen, Level_0Pal, Level_0PalLen, Level_0Map, Level_0MapLen);
    REG_BG0CNT = BG_SIZE0 | (10 << 8);

    InitPlayer(0,0);
}

void StepLogic(){
    StepPlayer();

    oam_copy(oam_mem, Warden.oamArray, Warden.oamCount);
}