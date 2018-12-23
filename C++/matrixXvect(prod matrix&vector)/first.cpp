#include <stdlib.h>
#include <iostream.h>
#include <stdio.h>
#include <malloc.h>
#include <conio.h>

void MxV(const double * M, unsigned n, unsigned m, const double * V, double * U)
  {const double * tV;

   for(unsigned i = 0; i < n; i++, U++)
     {*U = 0;
      tV = V;
      for(unsigned j = 0; j < m; j++, M++, tV++)
        *U += (*M) * (*tV);
     }
  }

int main()
{
  double M[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  double V[3] = {10, 11, 12};
  double U[3];

  cout << "Answer" << "\n";
  MxV(M, 3, 3, V, U);
  for(int i = 0; i < 3; i++)
    cout << U[i] << "\n";
  getch();
}