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

class instruction:
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
        self.wB = 0
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
        f2=f"{self.data}, {self.mode}, {self.COND}"
        f3=f"{self.RA}, {self.RB}, {self.RC}, {self.RD}, {self.RR}, {self.RID}, {self.RP}"
        f4=f"{self.WA}, {self.WB}, {self.WC}, {self.WD}, {self.WPC}, {self.WRA}, {self.WR}, {self.WOD}, {self.WPA}, {self.WPB}"
        f5="}"
        return f1 + f2 + f3 + f4 + f5