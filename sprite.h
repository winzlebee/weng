#pragma once

#include "util.h"

namespace weng {

class Sprite {
public:
    // Construct a sprite from 
    Sprite(const char *name);

    // Get the transform assosciated with this sprite
    const Transform2D &getTransform() { return m_transform; }

private:
    Transform2D m_transform;
};

}