#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
    std::string s = "";
    for(int i = 1; i < argc; i++)
    {
        s.append(argv[i]);
    }
    std::string new_s;
    int loop = s.length();
    for(int i = 0; i < loop; i++)
    {
        char c = s.back();
        s.pop_back();
        new_s.push_back(c);
    }

    std::cout << new_s << "\n";
}