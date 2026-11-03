#include <iostream>
#include <fstream>
#include <string>

void cat(std::ifstream& file)
{
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << '\n';
    }
}

int main(int argc, char *argv[]) {
    if(argc < 2)
    {
        std::cout << "usage: main [file] ...";
    }
    for(int i = 1; i < argc; i++)
    {
        
        
        std::ifstream file(argv[i]);
        if(!file.is_open())
        {
            std::cerr << "error: file invalid";
            continue;
        }
        cat(file);
    }
    
}