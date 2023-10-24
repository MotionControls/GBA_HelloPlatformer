#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <tonc.h>
#include "Defs.h"
#include "Sprites.h"

/* Funcs */
/*  Init();
    Acts before Step().
    Inits all assets and vars.
    Returns 0 on success.
*/
int Init(OBJ_ATTR* oamArr);

/*  Step();
    Acts every frame.
    Pretty much is the game.
    Returns oamCount.
*/
int Step(OBJ_ATTR* oamArr);

void UpdateOAM(OBJ_ATTR* oamArr);

#endif