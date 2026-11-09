#include "stack.h"
#include <iostream>
int main()
{
    Stack stack;
    for(int i = 1; i < 6; i++)
    {
        stack.push(i);
    }

    std::cout << stack.peek() << "\n";
    std::cout << stack.pop() << "\n";
    std::cout << stack.pop() << "\n";
    std::cout << stack.peek() << "\n";
}