#include "Player.h"

void InitPlayer(int tileID){
    player = (O_PLAYER){
        .tid = tileID,
        .rect = {0,0,16,16},
        .speed = {0,0},
    };
}

void StepPlayer(){}