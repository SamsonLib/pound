#include "cpu.h"
#include "jit.h"

#include <cstdio>

int main() {
    CPU cpu;
    cpu.pc = 0;

    // Simple ARMv8 program in memory (MOVZ X0, #5; ADD X0, X0, #3; RET)
    // These are placeholders; real encoding will be parsed later
    cpu.write_byte(0, 0x05); // MOVZ placeholder
    cpu.write_byte(4, 0x03); // ADD placeholder
    cpu.write_byte(8, 0xFF); // RET placeholder

    printf("%u\n", cpu.read_byte(0));

    JIT jit;
    jit.translate_and_run(cpu);

    cpu.print_debug_information();

    printf("X0 = %lu\n", cpu.x(0));
    return 0;
}