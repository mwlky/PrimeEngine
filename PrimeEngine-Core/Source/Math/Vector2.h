#ifndef PRIMEENGINE_VECTOR2_H
#define PRIMEENGINE_VECTOR2_H

#include <iostream>

namespace Prime {

    class Vector2 {
    public:
        float x;
        float y;

        Vector2();

        Vector2(float x, float y);

        friend Vector2 &operator+(Vector2 &v1, const Vector2 &v2);
        friend Vector2 &operator-(Vector2 &v1, const Vector2 &v2);
        friend Vector2 &operator*(Vector2 &v1, const Vector2 &v2);
        friend Vector2 &operator/(Vector2 &v1, const Vector2 &v2);

        Vector2 &operator+=(const Vector2 &vec);
        Vector2 &operator-=(const Vector2 &vec);
        Vector2 &operator*=(const Vector2 &vec);
        Vector2 &operator/=(const Vector2 &vec);

        Vector2& operator*(const int& i);
        Vector2& Zero();
        Vector2& Right();
        Vector2& Left();
        Vector2& Up();
        Vector2& Down();

        friend std::ostream& operator<<(std::ostream& stream, const Vector2& vec);

    private:
        Vector2 &Add(const Vector2 &vec);
        Vector2 &Subtract(const Vector2 &vec);
        Vector2 &Multiply(const Vector2 &vec);
        Vector2 &Divide(const Vector2 &vec);
    };

} // Prime

#endif //PRIMEENGINE_VECTOR2_H
