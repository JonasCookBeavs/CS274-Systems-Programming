#include <stdexcept>
#include <iostream>
#include <string>

class Holder
{
    private:
        int arr[50];
    public:
        Holder()
        {
            for (int i = 0; i < 50; i++)
                arr[i] = i * 10;
        }
        int get(int i);
};

int Holder::get(int i)
{
    if (i < 0 || i > 50)
        throw std::out_of_range("Index out of range\n");
    return arr[i];
};

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cerr << "No index given\n";
        return 1;
    }
    Holder h;
    int index;
    try {
         index = std::stoi(argv[1]);
    } catch (std::invalid_argument &) {
        std::cerr << "Invalid argument\n";
        return 1;
    } catch (std::out_of_range &) {
        std::cerr << "Invalid argument\n";
        return 1;
    }
    try {
        std::cout << h.get(index) << "\n";
    } catch (std::out_of_range &) {
        std::cerr << "Index out of range\n";
        return 1;
    }
    return 0;
}