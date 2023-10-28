#define ISMAIN

#include <stdlib.h>

#include "Logic.h"

int main(){
	InitLogic();
	
	REG_DISPCNT = DCNT_BG0 | DCNT_OBJ_1D | DCNT_OBJ;
	while(1){
		vid_vsync();
		key_poll();

		StepLogic();
	}
}