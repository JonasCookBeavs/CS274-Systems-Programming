#include "stack.h"
#include <iostream>

enum Day {
    Monday = 10,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

enum class Month {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

int main()
{
    mylib::Stack stack;
    stack.push(static_cast<int>(Month::March));
    stack.push(static_cast<int>(Month::November));
    stack.push(static_cast<int>(Month::December));

    stack.push(Day::Monday);
    stack.push(Day::Wednesday);
    stack.push(Day::Thursday);
    stack.push(Day::Friday);

    std::cout << stack.pop() << "\n";
    std::cout << stack.pop() << "\n";
    std::cout << stack.pop() << "\n";
    std::cout << stack.pop() << "\n";

    std::cout << static_cast<int>(stack.pop()) << "\n";
    std::cout << static_cast<int>(stack.pop()) << "\n";
    std::cout << static_cast<int>(stack.pop()) << "\n";
}