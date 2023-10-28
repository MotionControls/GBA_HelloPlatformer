#include "Player.h"

void InitPlayer(int tileID, int oamID){
    Player = (O_PLAYER){
        .tid = tileID,
        .oid = oamID,
        .x = 0, .y = 0,
        .rect = {0,0,16,16},
        .speed = {0,0},
    };

    InitSprite(tileID, S_Player_IdleTiles, S_Player_IdleTilesLen, S_Player_IdlePal, S_Player_IdlePalLen);
    obj_set_attr(&Warden.oamArray[oamID], ATTR0_4BPP, ATTR1_SIZE_16, 0);
    Warden.oamCount++;
}

void StepPlayer(){
    Player.speed.x = int2fx(key_tri_horz() * 2);
    Player.x = fxadd(Player.x, Player.speed.x);

    if(Player.y < SCR_HGT - 16){
        Player.speed.y = fxadd(Player.speed.y, int2fx(20));
        if(Player.speed.y > 4)
            Player.speed.y = 4;
    }else{
        Player.speed.y = 0;
        Player.y = SCR_HGT - 16;
    }

    Player.y = fxadd(Player.y, Player.speed.y);
    
    obj_set_pos(&Warden.oamArray[Player.oid], fx2int(Player.x), fx2int(Player.y));
}