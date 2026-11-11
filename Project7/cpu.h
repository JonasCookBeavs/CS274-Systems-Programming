#include "stack.h"

#define MAX_MEMORY 1024

class CPU
{
    private:
        int memory[MAX_MEMORY] = {};
        int pc = 0;
        Stack stack;

        enum Instructions {
            PUSH,
            POP,
            DUP,
            ADD,
            SUB,
            JZ,
            JNZ,
            PRT,
            SWAP,
            OVER,
            END
        };

        void push(int value);
        int pop();
        void dup();
        void add();
        void sub();
        void jz(int address);
        void jnz(int address);
        void prt();
        void swap();
        void over();
    public:
        void load(std::string filename);
        void run();
        void print_mem();
};