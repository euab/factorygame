#ifndef VEC2_H
#define VEC2_H

class Vector2
{
public:
    float x, y;

    Vector2();
    Vector2(const float &x, const float &y);

    friend const Vector2 operator+(const Vector2 &left, const Vector2 &right);
};

inline const Vector2 operator+(const Vector2 &left, const Vector2 &right)
{
    return Vector2(left.x + right.x, left.y + right.y);
}

#endif
