#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Matrix.hpp"

int main()
{
  double A[9] = {1, 2, 3,
                 4, 5, 6,
                 7, 8, 9};
  double B[6] = {6, 5, 4,
                 3, 2, 1};

  Matrix M1(3, A);
  M1.Display();
  printf("\n");
  Matrix M2(2, 3, B);
  M2.Display();
  Matrix M3(M1);
  M3.Display();

  /*Matrix M4(3);
  for(int i=1; i<4; i++)
    for(int j=1; j<4; j++)
      M4[i][j] = 2*i + j;
  M4.Display();*/

  /*Matrix M5((unsigned)2, (unsigned)3);
  for(int i=1; i<3; i++)
    for(int j=1; j<4; j++)
      M5[i][j] = 2*i + j;
  M5.Display();*/
  getch();
}