#include <cstdio>

#include "instr.hpp"
#include "vm.hpp"

std::vector<int> test_program = {
    PSH, 5,
    PSH, 6,
    ADD,
    POP,
    PSH, 10,
    PSH, 15,
    ADD,
    POP,
    SET, mbwk::VM::Registers::A, 6,
    SET, mbwk::VM::Registers::B, 9,
    PRN, mbwk::VM::Registers::A,
    PRN, mbwk::VM::Registers::B,
    HLT
};


int
main()
{
    using namespace mbwk::VM;

    load(&test_program);
    while (isRunning()) {
        eval(fetch());
        nextInstr();
    }

    return 0;
}

