#include <iostream>

#include "PixelGame.hpp"

PixelGame::PixelGame()
    : is_running_(false)
    , texture_manager_()
    , window_(nullptr)
    , renderer_(nullptr)
{
}

bool PixelGame::init(const char* p_title, const int p_width, 
                     const int p_height, const bool p_fullscreen)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }

    int flags = 0;
    if (p_fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    window_ = SDL_CreateWindow(p_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                               p_width, p_height, flags);
    if (window_ == nullptr)
    {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
    if (renderer_ == nullptr)
    {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        return false;
    }

    texture_manager_.loadTextures(renderer_);

    SDL_RenderSetLogicalSize(renderer_, p_width, p_height);
    is_running_ = true;
    return true;
}

void PixelGame::handleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                is_running_ = false;
                break;
            default:
                break;
        }
    }
}

void PixelGame::update()
{
}

void PixelGame::render()
{
    SDL_RenderClear(renderer_);

    SDL_SetRenderDrawColor(renderer_, 0, 0, 200, 255);

    texture_manager_.draw("ball", 0, 0, 32, 32, renderer_);

    SDL_RenderPresent(renderer_);
}

void PixelGame::clean()
{
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
    SDL_Quit();
}