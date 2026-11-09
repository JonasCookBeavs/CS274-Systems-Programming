#include <string>
#include <iostream>

class Stringer
{
private:
    int count = 0;
public:
    void print_string(std::string s);
    int get_count() { return count; };

};

void Stringer::print_string(std::string s) 
{ 
    std::cout << s; 
    count++;
}

int main()
{
    Stringer p1;
    Stringer p2;

    p1.print_string("Hello from p1!\n");
    p1.print_string("This is a test from p1!\n");
    std::cout << "p1's count: " << p1.get_count() << "\n";
    std::cout << "p2's count: " << p2.get_count() << "\n";
    p2.print_string("And this is p2\n");
    p2.print_string("And this is p2 printing more\n");
    p2.print_string("And this is p2 printing still more\n");
    std::cout << "p1's count: " << p1.get_count() << "\n";
    std::cout << "p2's count: " << p2.get_count() << "\n";
}