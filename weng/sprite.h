#pragma once

#include "util.h"

#include <string>

struct SDL_Texture;
struct SDL_Renderer;

namespace weng {

class Sprite {
public:

    friend class Game;

    // Construct a sprite from 
    Sprite(const char *name, const char *filename);
    ~Sprite();

    Transform2D transform;

private:
    void load(SDL_Renderer *renderer);
    void render(SDL_Renderer *renderer) const;


    std::string m_name;
    std::string m_file;

    // SDL Texture Management
    SDL_Texture *m_texture = nullptr;
};

}