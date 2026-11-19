#include <iostream>

class Animal {
public:
    virtual void sound() { std::cout << "Generic animal sound\n"; }
    virtual ~Animal() = default;
};

class Dog : public Animal {
    void sound() override { std::cout << "Woof\n"; }
};

class Cat : public Animal {
    void sound() override { std::cout << "Meow\n"; }
};

void make_sound(Animal &a)
{
    a.sound();
}

int main()
{
    Animal a;
    Cat c;
    Dog d;
    make_sound(a);
    make_sound(c);
    make_sound(d);
}