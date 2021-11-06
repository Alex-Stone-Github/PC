# typedef struct Instruction {
#     byte data; // data to be placed on the bus
#     byte processorMode;
#     // instructions for general purpose registers
#     bool RA;
#     bool RB;
#     bool RC;
#     bool RD;
#     bool WA;
#     bool WB;
#     bool WC;
#     bool WD;
#     // instructions for oddball registers and other inputs
#     bool WPC; //write program counter
#     bool WPA; //write proc B;
#     bool WPB; //write proc A
#     bool RP;  //read proc
#     bool WRA; //writeramaddress
#     bool WOD; // read from ports vs output to ports
#     bool RID;
#     // read ram and write ram
#     bool RR;
#     bool WR;
# } Instruction;