#include "Logic.h"

void InitLogic(){
    oam_init(Warden.oamArray, OAM_MAX);
    
    Warden = (O_WARDEN){
        .oamCount = 0,
        .curLevel = 0, .curScreen = 0, .maxScreen = 4,
        .camx = 0, .camy = 0,
        .tolxMin = 64, .tolxMax = 64,
    };
    InitBackground(Level_0Tiles, Level_0TilesLen, Level_0Pal, Level_0PalLen, Level_0Map, Level_0MapLen);
    REG_BG0CNT = BG_SIZE0 | (10 << 8);

    InitPlayer(0,0);
}

void StepLogic(){
    StepPlayer();
    ScrollScreen();

    oam_copy(oam_mem, Warden.oamArray, Warden.oamCount);
}

void ScrollScreen(){
    if(Player.x >= Warden.tolxMax + (SCR_WID/2)){
        Warden.camx++;
        Player.x--;
    }

    if(Player.x <= (SCR_WID/2) - Warden.tolxMin){
        Warden.camx--;
        Player.x++;
    }
    
    /*
    if(bgx > 0 && bgx % 16 == 0){
		if(levelID > 1 && bgx < 256*levelID)
			levelID--;
		if(levelID < 4 && bgx > 256*levelID)
			levelID++;
		int temp = (((bgx % 256) / 8) + 30) % 32;
		for(int y = 0; y < 32; y++){
			for(int x = temp; x < temp+2; x++){
				se_mem[20][x+32*y] = LevelMap[x+32*(y+(32*(levelID - (key_tri_horz() == -1))))];
			}
		}
	}
    */

    if(Warden.camx > 0 && Warden.camx % 16 == 0){
        if(Warden.curScreen > 1 && Warden.camx < 256 * Warden.curScreen)
            Warden.curScreen--;
        if(Warden.curScreen < Warden.maxScreen && Warden.camx > 256 * Warden.curScreen)
            Warden.curScreen++;
        
        int temp = (((Warden.camx % 256) / 8) + 30) % 32;
        for(int y = 0; y < 32; y++){
			for(int x = temp; x < temp+2; x++){
				se_mem[20][x+32*y] = Level_0Map[x+32*(y+(32*(Warden.curScreen-(Player.lastDir == 0))))];
			}
		}
    }
}