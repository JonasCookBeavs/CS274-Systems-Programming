#include <iostream>

class Stack
{
private:
    int stack[128];
    int index = -1;
public:
    void push(int value) { stack[++index] = value; };
    int pop() { return stack[index--]; };
    void dup() { push(stack[index]); };
    int prt() { std::cout << stack[index] << "\n"; };
};