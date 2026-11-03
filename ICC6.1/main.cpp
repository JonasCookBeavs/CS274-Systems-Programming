#include <iostream>
#include <format>

int main()
{
    for(int i = 1; i < 5; i++)
    {
        for(int j = 1; j < 5; j++)
        {
            std::cout << std::format("{} x {} = {}\n", i, j, i*j);
        }
    }
}
