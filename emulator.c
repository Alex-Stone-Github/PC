#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char byte;
typedef unsigned char ubyte;

typedef struct Instruction {
    byte data;
    byte processorMode;
    bool COND;

    bool RA;
    bool RB;
    bool RC;
    bool RD;
    bool RR;
    bool RID;
    bool RP;

    bool WA;
    bool WB;
    bool WC;
    bool WD;
    bool WPC;
    bool WRA;
    bool WR;
    bool WOD;
    bool WPA;
    bool WPB;
} Instruction;
void dumpInstructionState(Instruction* pInstruction) {
    Instruction instruction = * pInstruction;

    printf("data: %d, processorMode: %d, conditional: %d\n", (int)instruction.data, (int)instruction.processorMode, instruction.COND);

    printf("RA: %d, RB: %d, RC: %d, RD: %d, RR: %d, RID: %d, RP: %d\n", 
    instruction.RA, instruction.RB, instruction.RC, instruction.RD, instruction.RR, instruction.RID, instruction.RP);

    printf("WA: %d, WB: %d, WC: %d, WD: %d, WPC: %d, WRA: %d, WR: %d, WOD: %d, WPA: %d, WPB: %d\n", 
    instruction.RA, instruction.RB, instruction.RC, instruction.RD, instruction.WPC, instruction.WRA, instruction.WR, instruction.WOD,
    instruction.WPA, instruction.WPB);
}

typedef struct COMPUTER {
    byte A;
    byte B;
    byte C;
    byte D;
    byte PA;
    byte PB;
    ubyte PC;
    ubyte RA;
} COMPUTER;
COMPUTER init(){return (COMPUTER){0, 0, 0, 0, 255, 0};}

byte ALU(byte A, byte B, byte MODE) {
    return A + B;
}
void execute(COMPUTER* pComputer, Instruction* pInstructions, byte* ramBase, byte dataIn) {
    COMPUTER computer = *pComputer;
    Instruction instruction = *(pInstructions + computer.PC);

    bool shouldExecute = true;
    if (instruction.COND) {
        shouldExecute = (bool)computer.A;
    }

    if (shouldExecute) {
        byte bus = instruction.data;
        /*
        BUS MUTATION
        */
       if (instruction.RA) {bus = bus | computer.A;}
       if (instruction.RB) {bus = bus | computer.B;}
       if (instruction.RC) {bus = bus | computer.C;}
       if (instruction.RD) {bus = bus | computer.D;}
       if (instruction.RR) {bus = bus | *(ramBase + computer.RA);}
       if (instruction.RID) {bus = bus | dataIn;}
       if (instruction.RP) {bus = bus | ALU(computer.PA, computer.PB, instruction.processorMode);}

       if (instruction.WA) {computer.A = bus;}
       if (instruction.WB) {computer.B = bus;}
       if (instruction.WC) {computer.C = bus;}
       if (instruction.WD) {computer.D = bus;}
       if (instruction.WPC) {computer.PC = bus;}
       if (instruction.WRA) {computer.RA = bus;}
       if (instruction.WR) {ramBase[computer.RA] = bus;}
       if (instruction.WOD) {printf("%d\n", (int)bus);}
       if (instruction.WPA) {computer.PA = bus;}
       if (instruction.WPB) {computer.PB = bus;}
    }
}

#include "output.h"

int main() {
    COMPUTER computer = {0, 0, 0, 0, 0, 0, 255, 0};
    byte RAM[256] = {0};

    for (int i = 0; i < EPOCHS; i ++){dumpInstructionState(instrucions + i);}printf("\n"); //Print the instructiosn before running

    printf("+++++++++++++++++++++++++RUNNING+++++++++++++++++++++++++\n");
    printf("+++++++++++++++++++++++++RUNNING+++++++++++++++++++++++++\n");
    printf("+++++++++++++++++++++++++RUNNING+++++++++++++++++++++++++\n");
    for (unsigned int i = 0; i < EPOCHS; i ++) {
        computer.PC ++;
        printf("INSTRUCTION: %d\n", computer.PC);
        execute(&computer, (void*)&instrucions, RAM, 0);
    }
    return 0;
}