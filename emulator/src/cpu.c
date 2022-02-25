#include "cpu.h"

CPU initCPU() {
    return (CPU){0};
}
static byte ALUOUT(byte A, byte B, byte OPCODE) {
    // 1 = addition
    // 2 = subtraction
    // 3 = not
    // 4 = and
    // 5 = or

    //should be a switch, but who cares
    if (OPCODE == 1)
        return A + B;
    if (OPCODE == 2)
        return A - B;
    if (OPCODE == 3)
        return !A;
    if (OPCODE == 4)
        return A&B;
    if (OPCODE == 5)
        return A|B;
}
void execute(CPU* cpu, Instruction* instruction) {
    bool shouldExecute = false;
    if (instruction->useIF) {
        if (cpu->A > 0) {
            shouldExecute = true;
        }
        else; // Do nothing if there is no if
    }
    else
        shouldExecute = true;

    byte bus = instruction->bus;

    if (shouldExecute) {
        // READING
        if (instruction->readA)
            bus = bus|cpu->A;
        if (instruction->readB)
            bus = bus|cpu->B;
        if (instruction->readC)
            bus = bus|cpu->C;
        if (instruction->readD)
            bus = bus|cpu->D;
        if (instruction->readPROCOUT)
            bus = bus|ALUOUT(cpu->PROCA, cpu->PROCB, cpu->OPCODE);

        // WRITING
        if (instruction->writeA)
            cpu->A = bus;
        if (instruction->writeB)
            cpu->B = bus;
        if (instruction->writeC)
            cpu->C = bus;
        if (instruction->writeD)
            cpu->D = bus;
        if (instruction->writePROCA)
            cpu->PROCA = bus;
        if (instruction->writePROCB)
            cpu->PROCB = bus;
        if (instruction->writeOPCODE)
            cpu->OPCODE = bus;
        if (instruction->writeMEMADR)
            cpu->MEMADR = bus;
        if (instruction->writeINSPOI)
            cpu->INSPOI = bus;
        if (instruction->writeSTACKP)
            cpu->STACKP = bus;

        //OTHER
        if (instruction->writeIO)
            printf("PORT: %d, OUT: %d\n", (int)cpu->MEMADR, (int)bus);
    }
}




