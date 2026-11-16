#include <iostream>

void increment(int &x)
{
    x++;
}

int main()
{
    int a = 10;

    increment(a);

    std::cout << a << '\n';
}