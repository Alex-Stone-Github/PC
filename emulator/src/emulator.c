#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "cpu.h"
#include "types.h"

// Instruction instructions[] = {
//     (Instruction){77, false, 
//         false, false, false, false,
//         false, false, false, false,
// 
//         false, false, false, false,
// 
//         true, false, false,
// 
//         false, false},
//     (Instruction){100, false, 
//         false, false, false, false,
//         false, false, false, false,
// 
//         false, false, false, false,
// 
//         false, false, false,
// 
//         false, true},
// };
//

Instruction* instructions;

int main() {
    printf("Hello people\n");

    // highly spooky code
    instructions = malloc(sizeof(Instruction) * 10);
    memset(instructions, 0, sizeof(Instruction) * 10);
    FILE* file = fopen("instruct", "rb");
    if (!file) {
        printf("Could not open file");
        return 1;
    }
    fread(instructions, sizeof(Instruction) * 10, sizeof(Instruction), file);
    printf("%s\n", instructions);

    // cleanup cleanup everybody do their share
    free(instructions);
    return 0;
}
