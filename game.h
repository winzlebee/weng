
#pragma once

#include "sprite.h"

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

    Game(const char* name, void (*init)(Game*), void (*update)(Game*)) : m_name(name), f_init(init), f_update(update) {}

    ~Game();

    GameSettings settings;

    void begin();

    void loop();

    void addSprite(Sprite &s);

private:
    SDL_Window *m_window = nullptr;
    SDL_Renderer *m_renderer = nullptr;

    void (*f_init)(Game*);
    void (*f_update)(Game*);

    std::vector<Sprite> m_sprites;

    const char* m_name;

    bool m_init = false;
    bool m_quit = false;
};

}