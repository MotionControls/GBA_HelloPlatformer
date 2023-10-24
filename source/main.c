#define ISMAIN

#include <string.h>
#include <stdlib.h>
#include <math.h>

#include <tonc.h>

#include "Defs.h"
#include "Sprites.h"
#include "Logic.h"

int main(){
	REG_DISPCNT = DCNT_BG0 | DCNT_OBJ_1D | DCNT_OBJ;
	while(1){
		vid_vsync();
		key_poll();
	}
}