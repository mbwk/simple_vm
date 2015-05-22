#include <cstdio>

#include "instr.hpp"
#include "vm.hpp"

int registers[mbwk::VM::Registers::REGISTER_COUNT] = { 0 };
bool running = true;

#define STACK_MAX 256
int stack[STACK_MAX];

std::vector<int> *program;

bool
mbwk::VM::isRunning()
{
    return running;
}

void
mbwk::VM::nextInstr()
{
    ++registers[PC];
}

int
getInstr(int instr)
{
    return program->at(instr);
}

void
mbwk::VM::load(std::vector<int> *new_program)
{
    registers[PC] = 0;
    registers[SP] = -1;
    program = new_program;
}

int
mbwk::VM::fetch()
{
    return getInstr(registers[PC]);
}

void
mbwk::VM::eval(int instr)
{
    printf("%03d : %02x\n", registers[PC], instr);

    switch (instr) {
        case HLT:
            running = false;
            break;
            
        case PSH:
            ++registers[SP];
            nextInstr();
            stack[registers[SP]] = getInstr(registers[PC]);
            break;
        
        case POP:
            std::printf("popped %d\n", stack[registers[SP]--]);
            break;
        
        case ADD:
            registers[A] = stack[registers[SP]--];
            registers[B] = stack[registers[SP]--];
            registers[A] = registers[A] + registers[B];
            stack[++registers[SP]] = registers[A];
            break;

        case SET:
            nextInstr();
            ++registers[SP];
            stack[registers[SP]] = getInstr(registers[PC]);

            nextInstr();
            registers[stack[registers[SP]]] = getInstr(registers[PC]);
            --registers[SP];

            break;

        case PRN:
            nextInstr();
            std::printf("register %02X: %d\n", getInstr(registers[PC]), registers[getInstr(registers[PC])]);
            break;
    }
}

