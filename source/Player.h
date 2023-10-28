#ifndef PLAYER_H
#define PLAYER_H

#include <tonc.h>
#include "Defs.h"

#define PLAYER_ACCEL    0.05

void InitPlayer(int tileID, int oamID);
void StepPlayer();

#endif