#include "cpu.h"

int main(int argc, char* argv[])
{
    (void)argc;
    
    CPU cpu;
    cpu.load(argv[1]);
    cpu.run();
}