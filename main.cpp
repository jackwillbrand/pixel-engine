#include <SDL2/SDL.h>
#include <iostream>

#include "src/PixelGame.hpp"

int main(int argc, char* argv[])
{
    PixelGame game;

    if (!game.init("Pixel Game", 800, 600))
    {
        return -1;
    }

    while (game.isRunning())
    {
        game.handleEvents();
        game.update();
        game.render();
    }

    game.clean();

    return 0;
}
