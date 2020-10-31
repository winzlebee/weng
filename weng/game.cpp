#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "game.h"

namespace weng {

const char* InitException::what() const noexcept {
        return SDL_GetError();
}

const char* ImageException::what() const noexcept {
        return IMG_GetError();
}

Game::~Game() {
    if (m_init) {
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);

        IMG_Quit();
        SDL_Quit();
    }
}

void Game::addSprite(Sprite &s) {
    s.load(m_renderer);
    m_sprites.push_back(s);
}

void Game::begin() {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw InitException();
    }

    m_window = SDL_CreateWindow(m_name
        , SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED
        , settings.SCREEN_WIDTH, settings.SCREEN_HEIGHT
        , SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    
    if (m_window == nullptr) {
        throw InitException();
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    
    if (m_renderer == nullptr) {
        throw InitException();
    }

    // Render colour to dark blue as an engine default
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 127, 0);

    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        throw ImageException();
    }
    
    f_init(this);

    loop();
}

void Game::loop() {
    SDL_Event event;

    //Wait two seconds
    while (!m_quit) {
        // Input event processing
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym = SDLK_q) {
                    m_quit = true;
                }
            }

            if (event.type == SDL_QUIT) {
                m_quit = true;
            }
        }

        // Main scenegraph drawing and update operations
        SDL_SetRenderDrawColor(m_renderer, 0, 0, 127, 0xFF);
        SDL_RenderClear(m_renderer);

        for (const Sprite &s : m_sprites) {
            s.render(m_renderer);
        }

        SDL_RenderPresent( m_renderer );        
    }
}

}