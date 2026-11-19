#include <string>
#include <cmath>
#pragma once

#define PI 3.14159264
class Shape {
    public:
        virtual float area() = 0;
        virtual float circumference() = 0;
        virtual std::string name() = 0;
        virtual ~Shape() = default;
};

class Circle : public Shape {
    private:
        float radius;
    public:
        Circle(float radius) : radius{radius} {}
        float area() override { return PI * radius * radius; };
        float circumference() override { return 2 * PI * radius; };
        std::string name() override { return "Circle"; };
};

class Rectangle : public Shape {
    private:
        float width, height;
    public:
        Rectangle(float width, float height) : width{width}, height{height} {}
        float area() override { return width * height; };
        float circumference() override { return width * 2 + height * 2; };
        std::string name() override { return "Rectangle"; };
};

class RegularPolygon : public Shape {
    private:
        int sides;
        float length;
    public:
        RegularPolygon(int sides, float length) : sides{sides}, length{length} {}
        float area() override { return 0.25 * sides * (length * length) * (1.0 / std::tan(PI/sides)); };
        float circumference() override { return sides * length; };
        std::string name() override { return "Regular Polygon"; };
};

class RightTriangle : public Shape {
    private:
        float base, height;
    public:
        RightTriangle(float base, float height) : base{base}, height{height} {}
        float area() override { return 0.5 * base * height; };
        float circumference() override { return height + base + std::sqrt(height * height + base * base); };
        std::string name() override { return "Right Triangle"; };
};

class Square : public Shape {
    private:
        float length;
    public:
        Square(float length) :  length{length} {}
        float area() override { return length * length; }
        float circumference() override { return length * 4; }
        std::string name() override { return "Square"; };
};

class EquilateralTriangle : public RegularPolygon {
    public:
        EquilateralTriangle(float length) : RegularPolygon(3, length) {}
        std::string name() override { return "Equilateral Triangle"; };
};

class Pentagon : public RegularPolygon {
    public:
        Pentagon(float length) : RegularPolygon(5, length) {}
        std::string name() override { return "Pentagon"; };
};

class Hexagon : public RegularPolygon {
    public:
        Hexagon(float length) : RegularPolygon(6, length) {}
        std::string name() override { return "Hexagon"; };
};

class Megagon : public RegularPolygon {
    public:
        Megagon(float length) : RegularPolygon(1'000'00, length) {}
        std::string name() override { return "Megagon"; };
};