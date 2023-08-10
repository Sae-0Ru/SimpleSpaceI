#define SDL_MAIN_HANDLED
#include "game.h"
#include <SDL2/SDL.h>

int main(int argv, char** args)
{
    Game game;
    game.Run();

    return 0;
}