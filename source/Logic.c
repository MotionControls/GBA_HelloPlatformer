#include "Logic.h"

void InitLogic(){
    oam_init(Warden.oamArray, OAM_MAX);
    
    Warden = (O_WARDEN){
        .oamCount = 0,
        .curLevel = 0,
    };

    InitPlayer(0,0);
}

void StepLogic(){
    StepPlayer();

    oam_copy(oam_mem, Warden.oamArray, Warden.oamCount);
}