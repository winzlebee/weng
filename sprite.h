#pragma once

#include "math.h"

namespace weng {

class Sprite {
public:
    // Construct a sprite from 
    Sprite(const char *name);

    const Transform2D &getTransform();

private:
    Transform2D m_transform;
};

}