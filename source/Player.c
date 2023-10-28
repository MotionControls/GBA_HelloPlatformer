#include "Player.h"

void InitPlayer(int tileID, int oamID){
    Player = (O_PLAYER){
        .tid = tileID,
        .oid = oamID,
        .x = 0, .y = 0,
        .rect = {0,0,16,16},
        .xs = 0, .ys = 0,
        //.speed = {0,0},
    };

    InitSprite(tileID, S_Player_IdleTiles, S_Player_IdleTilesLen, S_Player_IdlePal, S_Player_IdlePalLen);
    obj_set_attr(&Warden.oamArray[oamID], ATTR0_4BPP, ATTR1_SIZE_16, 0);
    Warden.oamCount++;
}

void StepPlayer(){
    Player.xs = key_tri_horz() * 2;
    Player.x += Player.xs;

    if(Player.y < SCR_HGT - 16){
        Player.ys += 0.05;
        if(Player.ys > 4)
            Player.ys = 4;
    }else{
        Player.ys = 0;
        Player.y = SCR_HGT - 16;
    }

    Player.y += Player.ys;
    
    obj_set_pos(&Warden.oamArray[Player.oid], (int)Player.x, (int)Player.y);
}