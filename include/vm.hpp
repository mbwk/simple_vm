#ifndef VM_HPP
#define VM_HPP

#include <vector>

namespace mbwk { namespace VM {

typedef enum {
    A, B, C, D, E, F,
    PC, // program counter, aka instruction pointer
    SP, // stack pointer
    REGISTER_COUNT
} Registers;

bool isRunning();
void nextInstr();
void load(std::vector<int> *new_program);
int fetch();
void eval(int instr);

}}

#endif // VM_HPP

