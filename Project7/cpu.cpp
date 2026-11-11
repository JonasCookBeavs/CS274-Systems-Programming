#include <string>
#include <fstream>
#include <iostream>
#include "cpu.h"

static void trim_cr(std::string& s)
{
    if (!s.empty() && s.back() == '\r')
        s.pop_back();
}

void CPU::load(std::string filename)
{
    std::ifstream infile(filename);

    if (!infile.is_open())
        throw std::runtime_error("Failed to open file");
    
    std::string line;
    while(std::getline(infile, line))
    {
        trim_cr(line);
        if(line == "PUSH")
        {
            memory[pc++] = Instructions::PUSH;
            getline(infile, line);
            trim_cr(line);
            memory[pc++] = std::stoi(line);
        }
        else if(line == "POP")
            memory[pc++] = Instructions::POP;
        else if(line == "DUP")
            memory[pc++] = Instructions::DUP;
        else if(line == "ADD")
            memory[pc++] = Instructions::ADD;
        else if(line == "SUB")
            memory[pc++] = Instructions::SUB;
        else if(line == "JZ")
        {
            memory[pc++] = Instructions::JZ;
            getline(infile, line);
            trim_cr(line);
            memory[pc++] = std::stoi(line);
        }
        else if(line == "JNZ")
        {
            memory[pc++] = Instructions::JNZ;
            getline(infile, line);
            trim_cr(line);
            memory[pc++] = std::stoi(line);
        }
        else if(line == "PRT")
            memory[pc++] = Instructions::PRT;
        else if(line == "SWAP")
            memory[pc++] = Instructions::SWAP;
        else if(line == "OVER")
            memory[pc++] = Instructions::OVER;    
        else if(line == "END")
            memory[pc++] = Instructions::END;
    }
}

void CPU::run()
{
    pc = 0;
    while(memory[pc] != Instructions::END)
    {
        switch (memory[pc])
        {
            case 0:
                push(memory[++pc]);
                break;
            case 1:
                pop();
                break;
            case 2:
                dup();
                break;
            case 3:
                add();
                break;
            case 4:
                sub();
                break;
            case 5:
                jz(memory[++pc]);
                break;
            case 6:
                jnz(memory[++pc]);
                break;
            case 7:
                prt();
                break;
            case 8:
                swap();
                break;
            case 9:
                over();
                break;
        }
        pc++;
    }
}

void CPU::print_mem()
{
    for(int i = 0; i < MAX_MEMORY; i++)
    {
        std::cout << memory[i] << "\n";
    }
}

void CPU::push(int value)
{
    stack.push(value);
}

int CPU::pop()
{
    return stack.pop();
}

void CPU::dup()
{
    stack.push(stack.peek());
}

void CPU::add()
{
    int v1 = stack.pop();
    int v2 = stack.pop();
    stack.push(v1 + v2);
}

void CPU::sub()
{
    int v1 = stack.pop();
    int v2 = stack.pop();
    stack.push(v2 -v1);
}

void CPU::jz(int address)
{
    if(pop() == 0)
        pc = address - 1;
}

void CPU::jnz(int address)
{
    if(pop() != 0)
        pc = address - 1;
}

void CPU::prt()
{
    std::cout << stack.peek() << "\n";
}

void CPU::swap()
{
    int v1 = stack.pop();
    int v2 = stack.pop();
    stack.push(v1);
    stack.push(v2);
}

void CPU::over()
{
    int v1 = stack.pop();
    int v2 = stack.pop();
    stack.push(v2);
    stack.push(v1);
    stack.push(v2);
}