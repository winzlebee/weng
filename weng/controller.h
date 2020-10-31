
#include <SDL2/SDL.h>

namespace weng {

class Sprite;

class Controller
{
public:
    // Attaches to a sprite and handles events
    Controller(Sprite *sprite);

    virtual void update() = 0;
    virtual void init() = 0;
    virtual void keyDown(const uint32_t &code) = 0;

private:
    Sprite *m_sprite;
};

}