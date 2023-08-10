#ifndef CONSTANT_H
#define CONSTANT_H

#include <SDL2/SDL.h>

/**
 * @brief a namespace for all necessary constants to be used by different parts of the program.
 * 
 * @note by placing it in it's own file we can avoid a crash through cyclic inclusion
 * if it resides in higher up hierarchies. 
*/
namespace CONST
{
    const Uint32 MS_PER_SECOND = 1000;
    const Uint32 FRAMES_PER_SECOND = 60;
    const Uint32 MS_PER_FRAME = 1000 / 60;

    const int SCREEN_WIDTH = 720;
    const int SCREEN_HEIGHT = 720;

    const int X_GRID_COUNT = 16;
    const int Y_GRID_COUNT = 16;

    const int GRID_WIDTH = SCREEN_WIDTH / X_GRID_COUNT;
    const int GRID_HEIGHT = SCREEN_HEIGHT / Y_GRID_COUNT;
};

#endif