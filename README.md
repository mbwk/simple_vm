simple\_vm
==========

simple\_vm is an implementation of a basic virtual machine in C++.  It
was made mostly for learning purposes.

Based on this [blog post](http://www.blog.felixangell.com/virtual-machine-in-c/).


Instruction Set
---------------

The instruction set is detailed under ``include/instr.hpp``.

An overview:

:HLT: Halts the VM
:PSH: Pushes a value to the stack
:ADD: Adds together the two topmost values on the stack
:POP: Removes a value from the top of the stack
:SET: Sets the value of a given register to a given value
:PRN: Prints the value of a given register


TODO
----

1. Add more instructions (e.g. MUL, DIV)
2. Add the ability to read files containing opcodes
3. Write an assembler

