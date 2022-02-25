#ifndef TOKEN_HHH
#define TOKEN_HHH


typedef enum TOK_TYPE {
    ENDLINE,        //SEMICOLON
    INSTURCTION,    //INSTRUCTION
    INOUTARG,       //INPUT/OUTPUT ARGUMENT
    NUMBER,         //NUMBER ARGUMENT
} TOK_TYPE;

typedef enum INOUT {
    A,
    B,
    C,
    D,
    PROC,
    PROCA,
    PROCB,
    STACKP,
    INSPOI,
    MEMADR,
    IO,         // not currently working
} INOUT;

typedef struct Token {
    TOK_TYPE type;
    union {
        int value;
        INOUT name;
    };
} Token;

#endif // TOKEN_HHH
