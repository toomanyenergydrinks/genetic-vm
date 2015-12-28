#include "math.h"

const int program[] = {
  PSH, 5,
  PSH, 6,
  ADD,
  POP,
  HLT
};

/*const int bytecode_program[] = {
  0x6050,
  0x6160,
  0x2010,
  0x3000,
  0x0000
};*/

# define PROGRAM_LENGTH 100
int bytecode_program[PROGRAM_LENGTH];

void random_program();

void random_program() {

  srand(time(0));

  int length = rand() % 10;
  int n;
  for (n=0;n<length;n++) {
    bytecode_program[n] = rand() % 80000;
    printf("%d\r\n", bytecode_program[n]);
  }
}
