#include <string>
#include <iostream>
#include <vector>
#include "shape_class.h"

void print_shape(Shape& s)
{
    std::cout << s.name() << "\n";
    std::cout << "  area: " << s.area() << "\n";
    std::cout << "  circ: " << s.circumference() << "\n";
}

int main(int argc, char* argv[])
{
    std::vector<Shape*> shapes;
    for(int i = 1; i < argc; i++)
    {
        if(std::string(argv[i]) == "c")
            shapes.push_back(new Circle(std::stof(argv[++i])));
        else if(std::string(argv[i]) == "r")
        {
            float width = std::stof(argv[++i]);
            float height = std::stof(argv[++i]);
            shapes.push_back(new Rectangle(width, height));
        }
            
        else if(std::string(argv[i]) == "rp")
        {
            int sides = std::stoi(argv[++i]);
            float length = std::stof(argv[++i]);
            shapes.push_back(new RegularPolygon(sides, length));
        }
        else if(std::string(argv[i]) == "rt")
        {
            float base = std::stof(argv[++i]);
            float height = std::stof(argv[++i]);
            shapes.push_back(new RightTriangle(base, height));
        }
        else if(std::string(argv[i]) == "s")
            shapes.push_back(new Square(std::stof(argv[++i])));
        else if(std::string(argv[i]) == "et")
            shapes.push_back(new EquilateralTriangle(std::stof(argv[++i])));
        else if(std::string(argv[i]) == "p")
            shapes.push_back(new Pentagon(std::stof(argv[++i])));
        else if(std::string(argv[i]) == "h")
            shapes.push_back(new Hexagon(std::stof(argv[++i])));
        else if(std::string(argv[i]) == "m")
            shapes.push_back(new Megagon(std::stof(argv[++i])));
    }

    std::vector<std::string> max_area = {};
    std::vector<std::string> max_circ = {};
    float max_area_num = 0;
    float max_circ_num = 0;

    for(Shape* i : shapes)
    {
        print_shape(*i);
        if(i->area() >= max_area_num)
        {
            if(i->area() > max_area_num)
                max_area.clear();
            max_area_num = i->area();
            max_area.push_back(i->name());
        }
        if(i->circumference() >= max_circ_num)
        {
            if(i->circumference() > max_circ_num)
                max_circ.clear();
            max_circ_num = i->circumference();
            max_circ.push_back(i->name());
        }
        std::cout << "\n";
    }

    std::cout << "Shapes with max area " << max_area_num << "\n";
    for(std::string i : max_area)
    {
        std::cout << "  " << i << "\n";
    }
    std::cout << "\n";
    std::cout << "Shapes with max circumference " << max_circ_num << "\n";
    for(std::string i : max_circ)
    {
        std::cout << "  " << i << "\n";
    }

    for(Shape* i : shapes)
        delete i;
}