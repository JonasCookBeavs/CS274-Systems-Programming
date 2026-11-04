#include <fstream>

int main()
{
    std::ofstream outfile("foo.txt");
    for(int i = 1; i < 11; i++)
    {
        outfile << "Line " << i << "/10\n";
    }
}