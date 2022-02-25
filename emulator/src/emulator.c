#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "cpu.h"
#include "types.h"

Instruction instructions[] = {
    (Instruction){77, false, 
        false, false, false, false,
        false, false, false, false,

        false, false, false, false,

        true, false, false,

        false, false},
    (Instruction){100, false, 
        false, false, false, false,
        false, false, false, false,

        false, false, false, false,

        false, false, false,

        false, true},
};

int main() {
    printf("Hello people\n");
    CPU cpu = initCPU();
    execute(&cpu, &instructions[0]);
    execute(&cpu, &instructions[1]);
    return 0;
}
