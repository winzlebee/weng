#pragma once

#include <cmath>
#include <vector>

namespace weng {

// Convert degrees to radians
inline float radians(float degrees) {
    return degrees / 180.0f * M_PI;
}

inline float degrees(float radians) {
    return radians / M_PI * 180.0f;
}

struct Vec2 {
public:
    Vec2(float _x, float _y) : _coords{_x, _y} {}

    static Vec2 identity() {
        return Vec2(0, 0);
    }

    float &operator[](const int index) {
        return _coords[index];
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
        return this->x() * b.x() + this->y() * b.y();
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
    Vec2 &rotateBy(float angle) {
        angle = radians(angle);

        x()  = x()*cos(angle) - y()*sin(angle);
        y()  = x()*sin(angle) + y()*cos(angle);

        return *this;
    }

    void normalize() {
        x() /= magnitude();
        y() /= magnitude();
    }

    const float &x() const { return _coords[0]; }
    const float &y() const { return _coords[1]; }

    float &x() { return _coords[0]; }
    float &y() { return _coords[1]; }

private:
    float _coords[2];
};

Vec2 operator+(const Vec2 &a, const Vec2 &b);

Vec2 operator*(const Vec2 &a, float scalar);

class Transform2D {
public:
    // Declare a 2D transform from a position and rotation
    Transform2D(const Vec2 &_p, const float _r, Transform2D *parent = nullptr);
    
    // Declare a 2D transform with a position
    Transform2D(const Vec2 &_p, Transform2D *parent = nullptr);

    // Declare a 2D transform wtihout any parameters
    Transform2D(Transform2D *parent = nullptr);

    ~Transform2D();

    Transform2D *getParent() const { return m_parent; }

    void setParent( Transform2D *parent ) { m_parent = parent; }

    const std::vector<Transform2D*> getChildren() const { return m_children; }
    
    const Vec2 &getLocalPosition() const { return m_pos; }

    const float &getRotation() const { return m_rot; }

    void setLocalPosition(const Vec2 &pos) { m_pos = pos; };

    void setRotation(const float rotation) { m_rot = rotation; };

    void translate(float x, float y);

    void rotateBy(float angle);

    const Vec2 getWorldPosition() const;

private:
    Transform2D *m_parent = nullptr;
    std::vector<Transform2D*> m_children;

    Vec2 m_pos;
    float m_rot;
};

}
