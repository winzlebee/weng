#include <SDL2/SDL.h>

#include "game.h"

namespace weng {

const char* InitException::what() const noexcept {
        return SDL_GetError();
}

Sprite::Sprite(const char *name, const char *location) {
    
}

Game::~Game() {
    if (m_init) {
        SDL_FreeSurface(mainSurface);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
}

void Game::begin() {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw InitException();
    }

    window = SDL_CreateWindow("Game"
        , SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED
        , settings.SCREEN_WIDTH, settings.SCREEN_HEIGHT
        , SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    
    if (window == nullptr) {
        throw InitException();
    }

    //Get window surface
    mainSurface = SDL_GetWindowSurface( window );

    //Fill the surface white
    SDL_FillRect( mainSurface, NULL, SDL_MapRGB( mainSurface->format, 0xFF, 0xFF, 0xFF ) );
    
    //Update the surface
    SDL_UpdateWindowSurface( window );

    loop();
}

void Game::loop() {
    //Wait two seconds
    SDL_Delay( 2000 );
}

}