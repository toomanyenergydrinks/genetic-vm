#include <stdio.h>

int* int_to_bin(int integer);

// currently dumps bits 4 at a time
void bin_dump(int bitstring[])
{
  int x = 0;
  for (x=0;x<=31;x++){
    if ((x%4) == 0) {
      printf("\r\n4 bits\r\n");
    }
    printf("%d", bitstring[x]);
  }
  printf("\r\n");
}

// turn an integer into a binary string representation
int* int_to_bin(int integer)
{
  int c,k = 0;
  static int b[32];
  int n = 31;
  for(c=31;c>=0;c--) {
    k = integer >> c;
    b[n-c] = k&1;
  }
  // there's no return function here, return the result
  return b;
}

void print_bin(int integer) 
{
  bin_dump(int_to_bin(integer));
}
