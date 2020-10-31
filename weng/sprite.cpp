#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <exception>

#include "sprite.h"

namespace weng {

Sprite::Sprite(const char *name, const char *filename) : m_name(name), m_file(filename) {};

Sprite::~Sprite() {
    if (m_texture) {
        SDL_DestroyTexture(m_texture);
    }
}

void Sprite::load(SDL_Renderer *renderer) {
    SDL_Surface *surface = IMG_Load( m_file.c_str() );
    if( surface == nullptr )
    {
        throw std::exception();
    }

    //Create texture from surface pixels
    m_texture = SDL_CreateTextureFromSurface( renderer, surface );
    if( m_texture == NULL )
    {
        throw std::exception();
    }

    //Get rid of old loaded surface
    SDL_FreeSurface(surface);
}

void Sprite::render(SDL_Renderer *renderer) const {
    SDL_RenderCopy(renderer, m_texture, NULL, NULL);
}

}
