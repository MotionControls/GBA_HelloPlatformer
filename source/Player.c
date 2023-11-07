#include "Player.h"

void InitPlayer(int tileID, int oamID){
    Player = (O_PLAYER){
        .tid = tileID,
        .oid = oamID,
        .x = 0, .y = 0,
        .rect = {0,0,16,16},
        .xs = 0, .ys = 0,
        .lastDir = 0,
    };

    InitSprite(tileID, S_Player_IdleTiles, S_Player_IdleTilesLen, S_Player_IdlePal, S_Player_IdlePalLen);
    obj_set_attr(&Warden.oamArray[oamID], ATTR0_4BPP, ATTR1_SIZE_16, 0);
    Warden.oamCount++;
}

void StepPlayer(){
    Player.xs = key_tri_horz() * 2;
    if(Player.xs > 0)
        Player.lastDir = 1;
    else if(Player.xs < 0)
        Player.lastDir = 0;

    if(Player.y < SCR_HGT - 16){
        Player.ys += 0.05;
        if(Player.ys > 4)
            Player.ys = 4;
        
        if(Player.ys < 0 && !key_held(KEY_A))
            Player.ys /= 2;
    }else{
        Player.ys = 0;
        Player.y = SCR_HGT - 16;
        if(key_held(KEY_A))
            Player.ys = -1.5;
    }

    int gridx = ((int)Player.x / 8) % 32;
    int gridy = ((int)Player.y / 8) + (((int)Player.x / 8) / 32) + 1;

    for(int y = gridy - 2; y < gridy + 2; y++){
        for(int x = gridx - 2; x < gridx + 2; x++){
            if(Level_0Map[x+y*32] != 0){
                int col = GetCollision(x*8,y*8);
                /*if(col & 1)
                    Player.xs = 0;*/
                if(col & 2)
                    Player.ys = 0;
            }
        }
    }
    
    if(key_held(KEY_B)){
        Player.y--;
        Player.ys = 0;
    }

    if(key_held(KEY_R)){
        Player.x++;
    }

    Player.x += Player.xs;
    Player.y += Player.ys;
    
    obj_set_pos(&Warden.oamArray[Player.oid], (int)Player.x, (int)Player.y);
}

int GetCollision(int x, int y){
    int px, py;
    if(Player.xs == 0)
        px = 1;
    else
        px = (int)(Player.x + Player.xs);
    
    if(Player.ys == 0)
        py = 1;
    else
        py = (int)(Player.y + Player.ys);
    
    int whatCol = 0;

    if(px < x + 8 && px + 16 >= x)
        whatCol += 1;
    
    if(py < y + 8 && py + 16 >= y)
        whatCol += 2;
    
    return whatCol;
}