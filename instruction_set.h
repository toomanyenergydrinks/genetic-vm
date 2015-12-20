typedef enum {
  HLT,
  PSH,
  ADD,
  POP,
  SET,
  SUB,
  MOV,
  JMP,
  JMPA
} InstructionSet;

const char *StringInstructionSet[] = {"HLT", "PSH", "ADD", "POP", "SET", "SUB", "MOV","JMP","JMPA"};

typedef enum {
  A, B, C, D, E, F, 
  NUM_OF_REGISTERS
} Registers;
