#pragma once

#ifndef PIXEL_GAME_HPP
#define PIXEL_GAME_HPP

#include <SDL2/SDL.h>

#include "TextureManager.hpp"

class PixelGame
{
    public:
        PixelGame();
        ~PixelGame() = default;

        bool init(const char* p_title, const int p_width, const int p_height,
                  const bool p_fullscreen = false);

        void handleEvents();
        void update();
        void render();

        void clean();

        inline TextureManager& getTextureManager() { return texture_manager_; }

        inline bool isRunning() const { return is_running_; }
    
    private:
        bool is_running_;

        TextureManager texture_manager_;

        SDL_Window* window_;
        SDL_Renderer* renderer_;
};

#include "PixelGame.cpp"

#endif // PIXEL_GAME_HPP
