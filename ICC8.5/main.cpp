#include <cmath>
#include <iostream>

class Vector2d {
    public:
        float x = 0;
        float y = 0;
        Vector2d(float x, float y) : x{x}, y{y} {}
        virtual ~Vector2d() = default;
        virtual float magnitude() { return std::sqrt(x*x + y*y); }
};

class Vector3d : public Vector2d {
    public:
        float z = 0;
        Vector3d(float x, float y, float z) : Vector2d(x, y), z{z} {}
        float magnitude() override { return std::sqrt(x*x + y*y + z*z); }
};

int main()
{
    Vector2d v = Vector2d(2, 3);
    Vector3d v3 = Vector3d(2, 3, 4);
    std::cout << v.magnitude() << "\n";
    std::cout << v3.magnitude() << "\n";
}