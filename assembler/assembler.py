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
#     bool COND;
# } Instruction;

class Instruction:
    def __init__(self):
        #vars
        self.data = 0
        self.processorMode = 0
        #reg controls
        self.RA = False
        self.RB = False
        self.RC = False
        self.RD = False
        self.WA = False
        self.WB = False
        self.WC = False
        self.WD = False
        #others
        self.WPC = False
        self.WPA = False
        self.WPB = False
        self.RP = False
        self.WRA = False
        self.WOD = False
        self.RID = False
        self.RR = False
        self.WR = False
        self.COND = False

    def __str__(self):
        formate = "{}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}"
        return "{" + formate.format(self.data, self.processorMode, self.RA, self.RB, self.RC, self.RD, self.WA, self.WB, self.WC, self.WD, self.WPC, self.WPA, self.WPB, self.RP, self.WRA, self.WOD, self.RID, self.RR, self.WR, self.COND) + "}"

def convertToBinary(text):
    #convert to a more machine friendly format
    text = text.replace("\n", "")
    text = text.replace("\t", "")
    text = text.replace("\r", "")
    lines = text.split(";")
    lines.remove("")
    
    for line in lines:
        tokens = line.split(" ")
        conditional = False
        command = tokens[0]
        args = tokens[1:]
        if command[:2] == "if":
            conditional = True
            command = command[2:]

        
        if True: #scoping
            print(f"{conditional} {command} {args}")

with open("./assembler/input", "r") as f:
    convertToBinary(f.read())


i = Instruction()
print(i)