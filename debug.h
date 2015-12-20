#include <stdio.h>

int* int_to_bin(int integer);

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

int* int_to_bin(int integer)
{
  int c,k = 0;
  int b[32];
  int n = 31;
  for(c=31;c>=0;c--) {
    k = integer >> c;
    b[n-c] = k&1;
  }
  bin_dump(b);
}
