#pragma once

#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <map>
#include <string>

using std::string;

class TextureManager
{
    public:
        TextureManager() {}
        ~TextureManager() = default;

        bool loadTextures(SDL_Renderer* p_renderer);
        bool load(string p_path, string p_id, SDL_Renderer* p_renderer);
        bool draw(string p_id, int p_x, int p_y, int p_w, int p_h,
                  SDL_Renderer* p_renderer);
        bool drawFrame(string p_id, int p_x, int p_y, int p_w, int p_h,
                       int p_current_row, int p_current_frame,
                       SDL_Renderer* p_renderer);
    
    private:
        std::map<std::string, SDL_Texture*> textures_;
};

#include "TextureManager.cpp"

#endif // TEXTURE_MANAGER_HPP
