#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define PB(X) printf("%d\n", X); //Print a byte

typedef char byte;
typedef unsigned char ubyte;

typedef struct CPU {
    byte A;
    byte B;
    byte C;
    byte D;
    ubyte PC; // This is unsigned
    ubyte RA;
    byte PA;
    byte PB;
} CPU;
void reset(CPU* pcpu) {
    CPU cpu = *pcpu;
    cpu.A = 0;
    cpu.B = 0;
    cpu.C = 0;
    cpu.D = 0;
    cpu.PC = 255;
    cpu.RA = 0;
    cpu.PA = 0;
    cpu.PB = 0;
}


typedef struct Instruction {
    byte data; // data to be placed on the bus
    byte processorMode;
    // instructions for general purpose registers
    bool RA;
    bool RB;
    bool RC;
    bool RD;
    bool WA;
    bool WB;
    bool WC;
    bool WD;
    // instructions for oddball registers and other inputs
    bool WPC; //write program counter
    bool WPA; //write proc B;
    bool WPB; //write proc A
    bool RP;  //read proc
    bool WRA; //writeramaddress
    bool WOD; // read from ports vs output to ports
    bool RID;
    // read ram and write ram
    bool RR;
    bool WR;
} Instruction;
void printInstruction(Instruction* pInstruction) {
    Instruction instruction = *pInstruction;
    printf(
        "Data:                   ");
        PB(instruction.data);
    printf(
        "Processor Mode:         ");
        PB(instruction.processorMode);

    printf("REGISTER CONTROL LINES: RA, RB, RC, RD, WA, WB, WC, WD\n");
    printf(
        "REGISTER CONTROL LINES: %d, %d, %d, %d, %d, %d, %d, %d\n",
        instruction.RA, instruction.RB, instruction.RC, instruction.RD,
        instruction.WA, instruction.WB, instruction.WC, instruction.WD
    );
    printf("OTHER CONTROL LINES:    WPC, WPA, WPB, RP, WRA, WOD, RID, RR, WR\n");
    printf(
        "OTHER CONTROL LINES:    %d, %d, %d, %d, %d, %d, %d, %d, %d\n",
        instruction.WPC, instruction.WPA, instruction.WPB, instruction.RP, instruction.WRA,
        instruction.WOD, instruction.RID, instruction.RR, instruction.WR
    );
}


byte ALU(byte A, byte B, byte setting) {
    return A + B;
}
void execute(CPU* pcpu, Instruction* pInstructions, byte IOIN, byte* ram) {
    CPU cpu = *pcpu;
    cpu.PC ++;

    Instruction instruction = pInstructions[cpu.PC];
    byte bus = instruction.data;

    /*
        **********************BUS MUTATIONS********************************
        **********************BUS MUTATIONS********************************
        **********************BUS MUTATIONS********************************
    */
    //reading register values
    if (instruction.RA)
        bus = bus | cpu.A;
    if (instruction.RB)
        bus = bus | cpu.B;
    if (instruction.RC)
        bus = bus | cpu.C;
    if (instruction.RD)
        bus = bus | cpu.D;
    //reading from processor
    if (instruction.RP)
        bus = bus | ALU(cpu.PA, cpu.PB, instruction.processorMode);
    //reading from port
    if (instruction.RID)
        bus = bus | IOIN;
    //reading from ram
    if (instruction.RR)
        bus = bus | ram[cpu.RA];
    
    /*
        **********************REGISTER WRITING********************************
        **********************REGISTER WRITING********************************
        **********************REGISTER WRITING********************************
    */
    if (instruction.WA)
        cpu.A = bus;
    if (instruction.WB)
        cpu.B = bus;
    if (instruction.WC)
        cpu.C = bus;
    if (instruction.WD)
        cpu.D = bus;
    if (instruction.WRA)
        cpu.RA = bus;
    if (instruction.WR)
        ram[cpu.RA] = bus;
    if (instruction.WPA)
        cpu.PA = bus;
    if (instruction.WPB)
        cpu.PB = bus;
    if (instruction.WPC)
        cpu.PC = bus;
    if (instruction.WOD)
        printf("%d\n", (int)bus);
}


Instruction instructions[] = {
    {5, 6, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
};

int main() {
    // Set up cpu
    CPU cpu;
    reset(&cpu);

    // Set up ram
    byte RAM[256] = {0}; for(unsigned int i=0; i<256;i++){RAM[i]=0;}

    // Start to execute instructions
    execute(&cpu, (Instruction*)&instructions, 0, RAM);
    execute(&cpu, (Instruction*)&instructions, 0, RAM);
    execute(&cpu, (Instruction*)&instructions, 0, RAM);
    execute(&cpu, (Instruction*)&instructions, 0, RAM);

    return 0;
}