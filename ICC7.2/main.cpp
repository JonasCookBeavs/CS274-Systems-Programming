#include <iostream>
#include "printcounter.h"

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