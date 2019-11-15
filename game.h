
#pragma once

#include <exception>

struct SDL_Window;
struct SDL_Surface;

namespace weng {

class InitException : std::exception {
public:
    const char* what() const noexcept;
};

struct GameSettings {
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;
};

struct Sprite {
public:
    // Construct a sprite from 
    Sprite(const char *name, const char *location);

private:
    //SDL_Texture *texture;
};

class Game {
public:
    ~Game();

    GameSettings settings;

    void begin();

    void loop();

private:
    SDL_Window *window = nullptr;
    SDL_Surface *mainSurface = nullptr;

    bool m_init = false;
    bool m_quit = false;
};

}