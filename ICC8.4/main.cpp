#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cerr << "usage: fib n\n";
        return 1;
    }

    int n = std::stod(std::string(argv[1]));

    std::vector<int> numbers{};
    numbers.push_back(0);
    numbers.push_back(1);
    for (int i = 2; i < n; i++)
        numbers.push_back(numbers.at(i-1) + numbers.at(i-2));

    for (int i : numbers)
        std::cout << i << '\n';
}