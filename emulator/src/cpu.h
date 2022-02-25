#ifndef CPU_HHH
#define CPU_HHH

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "types.h"

typedef struct CPU {
    byte PROCA;
    byte PROCB;
    byte OPCODE;
    byte MEMADR;
    
    byte A;
    byte B;
    byte C;
    byte D;

    byte STACKP;
    byte INSPOI;
} CPU;

// Here are some opcodes btw
    // 1 = addition
    // 2 = subtraction
    // 3 = not
    // 4 = and
    // 5 = or
typedef struct Instruction {
    byte bus;
    
    bool useIF;

    bool writeA;
    bool writeB;
    bool writeC;
    bool writeD;
    bool readA;
    bool readB;
    bool readC;
    bool readD;

    bool writePROCA;
    bool writePROCB;
    bool readPROCOUT;
    bool writeOPCODE;
    
    bool writeMEMADR;
    bool writeINSPOI;
    bool writeSTACKP;

    bool readIO;
    bool writeIO;
} Instruction;

CPU initCPU();
static byte ALUOUT(byte A, byte B, byte OPCODE);
void execute(CPU* cpu, Instruction* instruction);

#endif // CPU_HHH
