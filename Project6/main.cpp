#include <cctype>
#include <iostream>
#include <fstream>

enum State
{
    at_start,
    in_space,
    in_non_space,
};

int main(int argc, char *argv[])
{
    (void)argc;
    
    std::ifstream file(argv[1]);
    char ch;
    int word_count = 0;
    State state = at_start;
    while (file.get(ch))
    {
        switch (state)
        {
        case 0:
            if (std::isspace(ch))
            {
                state = in_space;
                break;
            }
            else
            {
                state = in_non_space;
                word_count++;
                break;
            }
        case 1:
            if (std::isspace(ch))
            {
                state = in_space;
                break;
            }
            else
            {
                state = in_non_space;
                word_count++;
                break;
            }
        case 2:
            if (std::isspace(ch))
            {
                state = in_space;
                break;
            }
            else
            {
                state = in_non_space;
                break;
            }
        }
    }

    std::cout << word_count << "\n";
}
