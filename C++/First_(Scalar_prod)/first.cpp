#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <malloc.h>
using namespace std;

double *a;
int n;

double InnerProd(const double *a, const double *b, unsigned n)
  {double s = 0;
   for(unsigned j = 0; j < n; j++, a++, b++)
     s += (*a) * (*b);

   return s;
  }

int main()
{
  cout << "Enter array size \n";
  cin >> n;
  a = (double*)malloc(n*sizeof(double));
  cout << "Enter elements of array\n";
  for (int i = 0; i < n; i++)
    cin >> a[i];
  cout(minArray(a[1], a[n]));
  getchar;
}
