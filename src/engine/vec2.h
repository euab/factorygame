#ifndef ENGINE_VEC2_H
#define ENGINE_VEC2_H

class Vector2
{
public:
    const static Vector2 V_ZERO;
    const static Vector2 V_UP;
    const static Vector2 V_DOWN;
    const static Vector2 V_LEFT;
    const static Vector2 V_RIGHT;

    Vector2();
    Vector2(const float &x, const float &y);

    float x, y;

    friend const Vector2 operator+(const Vector2 &left, const Vector2 &right);
    friend const Vector2 operator-(const Vector2 &left, const Vector2 &right);
    friend const Vector2 operator*(const Vector2 &left, const Vector2 &right);
    friend const Vector2 operator*(const Vector2 &left, const float &scale);

    Vector2 &operator=(const Vector2 &right);
    Vector2 &operator+=(const Vector2 &right);
};

inline Vector2::Vector2(): x(0.0f), y(0.0f) { }

inline Vector2::Vector2(const float &x, const float &y): x(x), y(y) { }

inline const Vector2 operator+(const Vector2 &left, const Vector2 &right)
{
    return Vector2(left.x + right.x, left.y + right.y);
}

inline const Vector2 operator-(const Vector2 &left, const Vector2 &right)
{
    return Vector2(left.x - right.x, left.y - right.y);
}

inline const Vector2 operator*(const Vector2 &left, const Vector2 &right)
{
    return Vector2(left.x * right.x, left.y * right.y);
}

inline const Vector2 operator*(const Vector2 &left, const float &scale)
{
    return Vector2(left.x * scale, left.y * scale);
}

inline Vector2& Vector2::operator=(const Vector2 &right)
{
    // Check for self assignment
    if (this != &right) {
        this->x = right.x;
        this->y = right.y;
    }

    return *this;
}

inline Vector2& Vector2::operator+=(const Vector2 &right)
{
    this->x += right.x;
    this->y += right.y;

    return *this;
}

#endif // ENGINE_VEC2_H
