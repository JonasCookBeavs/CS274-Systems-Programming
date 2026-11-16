#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
    (void)argc;
    int iterations = std::stoi(argv[1]);
    int* arr = new int[iterations];
    arr[0] = 0;
    arr[1] = 1;
    std::cout << arr[0] << '\n';
    std::cout << arr[1] << '\n';
    for(int i = 2; i < iterations; i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
        std::cout << arr[i] << '\n';
    }

    delete[] arr;
}