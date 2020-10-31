#include "util.h"

#include <algorithm>

namespace weng {

Vec2 operator+(const Vec2 &a, const Vec2 &b) {
    return Vec2(a.x() + b.x(), a.y() + b.y());
}

Vec2 operator*(const Vec2 &a, float scalar) {
    return Vec2(a.x() * scalar, a.y() * scalar);
}

Transform2D::Transform2D(const Vec2 &_p, const float _r, Transform2D *parent)
 : m_pos(_p)
 , m_rot(_r)
 , m_parent(parent) {

    if (m_parent) {
        m_parent->m_children.push_back(this);
    }
}

Transform2D::Transform2D(const Vec2 &_p, Transform2D *parent) : Transform2D(_p, 0, parent) {}

Transform2D::Transform2D(Transform2D *parent) : Transform2D(Vec2::identity(), parent) {}

Transform2D::~Transform2D() {
    // Detach all child transforms to point to nowhere
    for (auto *child : m_children) {
        child->m_parent = nullptr;
    }

    // Remove this transform from any parent transform
    if (m_parent) {
        auto &parentChildren = m_parent->m_children;
        auto index = std::remove(parentChildren.begin(), parentChildren.end(), this);
        parentChildren.erase(index);
    }
}

const Vec2 Transform2D::getWorldPosition() const {
    // The world position of a transform can be calculated by traversing the parent tree
    const Transform2D *currentTransform = this;
    Vec2 finalPosition = Vec2::identity();

    // Iterate over the transform tree to get the world position of this object
    while (currentTransform = currentTransform->getParent()) {
        Vec2 transVector = currentTransform->getLocalPosition();
        finalPosition += transVector.rotateBy(currentTransform->getRotation());
    }

    return finalPosition;
}

void Transform2D::translate(float x, float y) {
    m_pos.x() += x;
    m_pos.y() += y;
}

void Transform2D::rotateBy(float angle) {
    m_rot = std::fmod(m_rot + angle, 360.0f);
}

}