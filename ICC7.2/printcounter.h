#include <string>
#pragma once

class Stringer
{
private:
    int count = 0;
public:
    void print_string(std::string s);
    int get_count() { return count; };
};