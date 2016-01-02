typedef enum {
  HLT,
  PSH,
  ADD,
  POP,
  SET,
  SUB,
  MOV,
  JMP,
  JMPA,
  JMPB,
  INC,
  DEC,
  MUL,
  NOP,
  AND
} InstructionSet;

const char *StringInstructionSet[] = {"HLT", "PSH", "ADD", "POP", "SET", "SUB", "MOV","JMP","JMPA","JMPB","INC","DEC","MUL","NOP","AND"};

typedef enum {
  A, B, C, D, E, F, 
  NUM_OF_REGISTERS
} Registers;
