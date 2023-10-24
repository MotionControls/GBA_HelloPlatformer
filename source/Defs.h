#ifndef DEFS_H
#define DEFS_H

#include <tonc.h>

#ifndef ISMAIN
    #define def
#else
    #define def extern
#endif

#define OAM_MAX     128     // Max amount of objects allowed.

#endif