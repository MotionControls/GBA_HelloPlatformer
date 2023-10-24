#define ISMAIN

#include <string.h>
#include <stdlib.h>
#include <math.h>

#include <tonc.h>

#include "Defs.h"
#include "Sprites.h"

int main(){
	LZ77UnCompVram(LevelTiles, tile_mem[0]);
	GRIT_CPY(pal_bg_mem, LevelPal);
	memcpy16(&se_mem[20][0], LevelMap, LevelMapLen);
	REG_BG0CNT = BG_SIZE0 | (20 << 8);
	
	s16 bgx = 0, bgy = 0;
	int levelID = 1;
	REG_DISPCNT = DCNT_BG0;
	while(1){
		vid_vsync();
		key_poll();

		if(key_tri_horz() == -1 && bgx > 0){
			bgx--;
		}else if(key_tri_horz() == 1 && bgx <= 256*3){
			bgx++;
		}
		
		
		if(key_tri_vert() == -1)
			bgy--;
		else if(key_tri_vert() == 1)
			bgy++;
			
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

		REG_BG0HOFS = bgx;
	}
}