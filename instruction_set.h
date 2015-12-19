typedef enum {
  HLT,
  PSH,
  ADD,
  POP,
  SET,
  SUB,
  MOV
} InstructionSet;

const char *StringInstructionSet[] = {"HLT", "PSH", "ADD", "POP", "SET", "SUB", "MOV"};

typedef enum {
  A, B, C, D, E, F, 
  NUM_OF_REGISTERS
} Registers;
