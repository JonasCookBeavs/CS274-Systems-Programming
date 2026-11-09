#include "printcounter.h"
#include <iostream>

void Stringer::print_string(std::string s) 
{ 
    std::cout << s; 
    count++;
}