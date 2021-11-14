# typedef struct Instruction {
#     byte data;
#     byte processorMode;
#     bool COND;

#     bool RA;
#     bool RB;
#     bool RC;
#     bool RD;
#     bool RR;
#     bool RID;
#     bool RP;

#     bool WA;
#     bool WB;
#     bool WC;
#     bool WD;
#     bool WPC;
#     bool WRA;
#     bool WR;
#     bool WOD;
#     bool WPA;
#     bool WPB;
# } Instruction;

class Instruction:
    def __init__(self):
        self.data = 0
        self.mode = 0
        self.COND = 0

        self.RA = 0
        self.RB = 0
        self.RC = 0
        self.RD = 0
        self.RR = 0
        self.RID = 0
        self.RP = 0

        self.WA = 0
        self.WB = 0
        self.WC = 0
        self.WD = 0
        self.WPC = 0
        self.WRA = 0
        self.WR = 0
        self.WOD = 0
        self.WPA = 0
        self.WPB = 0
    
    def __str__(self):
        f1="{"
        f2=f"{self.data}, {self.mode}, {self.COND}, "
        f3=f"{self.RA}, {self.RB}, {self.RC}, {self.RD}, {self.RR}, {self.RID}, {self.RP}, "
        f4=f"{self.WA}, {self.WB}, {self.WC}, {self.WD}, {self.WPC}, {self.WRA}, {self.WR}, {self.WOD}, {self.WPA}, {self.WPB}"
        f5="}"
        return f1 + f2 + f3 + f4 + f5

def convertToBinary(text):
    output = "Instruction instrucions = {\n"
    instruction = Instruction()
    text = text.replace("\n", "")
    lines = text.split(";")

    for line in lines:
        tokens = line.split(" ")
        command = tokens[0]
        args = tokens[1:]

        if command == "put":
            instruction.data = args[0]
        if command == "step":
            output += str(instruction) + ",\n"
            instruction = Instruction()
        
        if command == "write":
            for arg in args:
                if arg == "A": instruction.WA = 1
                if arg == "B": instruction.WB = 1
                if arg == "C": instruction.WC = 1
                if arg == "D": instruction.WD = 1
                if arg == "PC": instruction.WPC = 1
                if arg == "RA": instruction.WRA = 1
                if arg == "RAM": instruction.WR = 1
                if arg == "OD": instruction.WOD = 1
                if arg == "PA": instruction.WPA = 1
                if arg == "PB": instruction.WPB = 1

        if command == "read":
            for arg in args:
                if arg == "A": instruction.RA = 1
                if arg == "B": instruction.RB = 1
                if arg == "C": instruction.RC = 1
                if arg == "D": instruction.RD = 1
                if arg == "RAM": instruction.RR = 1
                if arg == "ID": instruction.RID = 1
                if arg == "P": instruction.RP = 1
    output += "};"
    return output
        

with open("input", "r") as f:
    print(convertToBinary(f.read()))