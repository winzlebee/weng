
#pragma once

#include <cmath>
#include <vector>

namespace weng {

// Convert degrees to radians
float radians(float degrees) {
    return degrees / 180.0f * M_PI;
}

float degrees(float radians) {
    return radians / M_PI * 180.0f;
}

struct Vec2 {
public:
    Vec2(float _x, float _y) : x(_x), y(_y) {}

    static Vec2 identity() {
        return Vec2(0, 0);
    }

    float &operator[](const int index) {
        return coords[index];
    }

    Vec2 &operator+=(const Vec2 &other) {
        x() += other.x();
        y() += other.y();

        return *this;
    }

    Vec2 &operator*=(float scalar) {
        x() *= scalar;
        y() *= scalar;

        return *this;
    }

    // Returns the dot product of this vector and another
    float dot(const Vec2 &b) const {
        return this.x * b.x + this.y * b.y;
    }
    
    // Returns the angle between this vector and another in degrees
    float angle(const Vec2 &b) const {
        return degrees(acos(dot(b)));
    }

    // Magnitude of the vector
    float magnitude() const {
        return sqrt(dot(*this));
    }

    // Rotate the current vector anticlockwise by the specified angle
    Vec2 &rotateBy(const float angle) {
        angle = radians(angle);

        x()  = x*cos(angle) - y()*sin(angle);
        y()  = x*sin(angle) + y()*cos(angle);

        return *this;
    }

    void normalize() {
        x() /= magnitude;
        y() /= magnitude;
    }

    float &x() const {
        return coords[0];
    }

    float &y() const {
        return coords[1];
    }

private:
    float _coords[2];
};

Vec2 operator+(const Vec2 &a, const Vec2 &b) {
    return Vec2(a.x() + b.x(), a.y() + b.y());
}

Vec2 operator*(const Vec2 &a, float scalar) {
    return Vec2(a.x() * scalar, a.y() * scalar);
}

class Transform2D {

    // Declare a 2D transform from a position and rotation
    Transform2D(const Vec2 &_p, const float _r, const Transform2D *parent = nullptr) : m_pos(p), m_rot(r), m_parent(parent) {}

    // Declare a 2D transform with a position
    Transform2D(const Vec2 &_p, const Transform2D *parent = nullptr) : Transform2D(_p, 0, parent) {}

    Transform2D *getParent() const {
        return m_parent;
    }
    
    const Vec2 &getLocalPosition() const { return m_pos; }

    const float &getRotation() const { return m_rot; }

    const Vec2 getWorldPosition() const {
        // The world position of a transform can be calculated by traversing the parent tree
        Transform2D *currentTransform = this;
        Vec2 finalPosition = Vec2::identity();

        // Iterate over the transform tree to get the world position of this object
        while (currentTransform = currentTransform->getParent()) {
            Vec2 transVector = currentTransform->getLocalPosition();
            finalPosition += transVector.rotateBy(currentTransform->getRotation());
        }

        return finalPosition;
    }

private:
    Transform2D *m_parent = nullptr;
    Vec2 m_pos;
    float m_rot;
};

}