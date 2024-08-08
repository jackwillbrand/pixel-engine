#include <iostream>

#include "TextureManager.hpp"

bool TextureManager::loadTextures(SDL_Renderer* p_renderer)
{
    bool result = true;
    result &= load("assets/textures/ball.png", "ball", p_renderer);

    return true;
}

bool TextureManager::load(string p_path, string p_id, SDL_Renderer* p_renderer)
{
    SDL_Surface* surface = IMG_Load(p_path.c_str());
    if (surface == nullptr)
    {
        std::cerr << "IMG_Load Error: " << IMG_GetError() << std::endl;
        return false;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(p_renderer, surface);
    if (texture == nullptr)
    {
        std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        return false;
    }

    SDL_FreeSurface(surface);
    textures_[p_id] = texture;
    return true;
}

bool TextureManager::draw(string p_id, int p_x, int p_y, int p_w, int p_h,
                          SDL_Renderer* p_renderer)
{
    SDL_Rect src_rect = {0, 0, p_w, p_h};
    SDL_Rect dest_rect = {p_x, p_y, p_w, p_h};

    SDL_RenderCopy(p_renderer, textures_[p_id], &src_rect, &dest_rect);
    return true;
}

bool TextureManager::drawFrame(string p_id, int p_x, int p_y, int p_w, int p_h,
                               int p_current_row, int p_current_frame,
                               SDL_Renderer* p_renderer)
{
    SDL_Rect src_rect = {p_w * p_current_frame, p_h * p_current_row, p_w, p_h};
    SDL_Rect dest_rect = {p_x, p_y, p_w, p_h};

    SDL_RenderCopy(p_renderer, textures_[p_id], &src_rect, &dest_rect);
    return true;
}

