#include "instruction_set.h"
#include "test_program.h"
#include "debug.h"

#define DEBUG 1
#define NUM_REGISTERS 15
#define SP 0
//registers[ SP ]

// stack pointer
int sp = -1;
int stack[256];

// instruction pointer
int ip = 0;

// system state
int running = 1;

void eval(int instr);
void decode(int instr);

int main() 
{
  random_program();
  while (running)
  {
    eval(fetch());
//    ip++;  
  }
  return 0;
}

/*
  instruction decoding function:
  take two bytes and parse out the relevant information
*/

int registers[ NUM_REGISTERS ];
int instrNum;
int c1;
int c2;
int c3;

void decode(int instr)
{
  instrNum = (instr & 0xF000) >> 12;
  c1     = (instr & 0xF00) >> 8;
  c2     = (instr & 0xF0) >> 4;
  c3     = (instr & 0xF);
  if (DEBUG) {
    printf("Instruction Code: %d\r\n", instrNum);
    printf("C1 Code: %d\r\n", c1);
    printf("C2 Code: %d\r\n", c2);
    printf("C3 Code: %d\r\n", c3);
  }
}


void eval(int instr) 
{
  decode(instr);
  char tmp[16];
  if (instrNum <= 5) {
    if (DEBUG)
      printf("%s %d %d %d (GENE: %d)\r\n", StringInstructionSet[instrNum], c1, c2, c3, instr);
  }
//  exit(0);
  switch(instrNum) {
    case HLT: {
      running = 0;
      break;
    }
    case MOV: {
//      sp++;
      registers[ c1 ] = c2;
      if (DEBUG)
        printf("Placed %d in register %d\n", c2, c1);
//      stack[sp] = program[++ip];
      break;
    }
    case PSH: {
      sp++;
      stack[sp] = c2;
      break;
    }
    case POP: {
      registers[ c2 ] = stack[sp];
      if (DEBUG)
        printf("Popped %d\n", registers[ c2 ]);
      break;
    }
    case ADD: {
      int a = registers[c1];
      int b = registers[c2];
      int result = b + a;
      stack[sp] = result;
      if (DEBUG)
        printf("Added %d to %d\n", a, b);
      break;
    }
    case SUB: {
     int a = registers[c1];
     int b = registers[c2];
     int result = a - b;
     if (DEBUG)
       printf("Subtracted %d from %d\r\n", a, b);
     stack[sp] = result;
    }
    case JMP: {
      ip = registers[c1];
      printf("Jumped to %d\r\n", ip);
      break;
    }
    case JMPA: {
      ip = registers[registers[c1]];
      printf("Jumped to %d\r\n", registers[registers[c1]]);
      break;
    }
    default: {
      /* in the case of an unknown opcode, halt and freak the hell out */
      running = 0;
      break;
    }
  }
  ip++;
}

int fetch() 
{
  return bytecode_program[ip];
}
