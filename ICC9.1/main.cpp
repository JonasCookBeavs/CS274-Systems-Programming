#include <iostream>
#include <vector>

// The objects got sliced to the base Animal class, so they all make generic animal sounds

class Animal {
public:
    virtual ~Animal() = default;
    virtual void sound() { std::cout << "Generic animal sound\n"; }
};

class Cat : public Animal {
public:
    void sound() override { std::cout << "Meow\n"; }
};

class Dog : public Animal {
public:
    void sound() override { std::cout << "Arf!\n"; }
};

int main()
{
    Animal a;
    Cat c;
    Dog d;

    a.sound();
    c.sound();
    d.sound();

    std::vector<Animal*> v;
    v.push_back(&a);
    v.push_back(&c);
    v.push_back(&d);

    for (auto a : v)
    {
        a->sound();
    }
}