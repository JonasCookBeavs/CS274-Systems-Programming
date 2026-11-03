#include <iostream>
#include <format>

int main()
{
    for(int i = 1; i < 13; i++)
    {
        for(int j = 1; j < 13; j++)
        {
            std::cout << std::format("{:4}", i*j);
        }
        std::cout << "\n";
    }
}
