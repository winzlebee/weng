
#pragma once

#include <exception>

struct SDL_Window;
struct SDL_Renderer;

namespace weng {

class InitException : std::exception {
public:
    const char* what() const noexcept override;
};

class ImageException : std::exception {
public:
    const char* what() const noexcept override;
};

struct GameSettings {
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;
};

class Game {
public:
    ~Game();

    GameSettings settings;

    void begin();

    void loop();

private:
    SDL_Window *m_window = nullptr;
    SDL_Renderer *m_renderer = nullptr;

    bool m_init = false;
    bool m_quit = false;
};

}