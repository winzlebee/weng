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

    // Get the transform assosciated with this sprite
    const Transform2D &getTransform() { return m_transform; }

private:
    void load(SDL_Renderer *renderer);
    void render(SDL_Renderer *renderer) const;

    Transform2D m_transform;

    std::string m_name;
    std::string m_file;

    // SDL Texture Management
    SDL_Texture *m_texture = nullptr;
};

}