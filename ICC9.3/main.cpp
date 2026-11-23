#include <iostream>

// The output is a double free error
// You would hope that there would be two instances of a constructor and destructor
// Under the hood, both data and data2 attempt to free the same data, since data2 isn't a copy, just a reference.

class MyData
{
    private:
        int *data;
    public:
        MyData(int size) : data{new int[size]} {
            std::cout << "=== CTOR: size " << size << "\n";
        };
        ~MyData() {
            delete[] data;
            std::cout << "=== DTOR" << "\n";
        }
        int& at(int index) { return data[index]; }
};

int main()
{
    MyData data(10);
    
    data.at(3) = 999;
    std::cout << data.at(3) << "\n";

    MyData data2 = data;
}