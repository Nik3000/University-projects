#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Matrix.hpp"

int main()
{
  double A[12] = {1, 2, 3,  //for read
                 4, 5, 6,
                 7, 8, 9,
                 10, 11, 12};
  double B[3] = {1, 2, 3};

  printf("First tests \n");
  int n1 = 1;
  int n2 = 2;
  Matrix M1(4, 3, A);  //square constructor
  printf("Initial Matrix \n");
  M1.Display();
  printf("\nAfter SwapRows first and second \n");
  M1.SwapRows(n1, n2);
  M1.Display();

  int n = 2;
  double k = 3;
  Matrix M2(4, 3, A);
  printf("After ProdRows. Coef = 3\n");
  M2.ProdRows(n, k);
  M2.Display();

  n1 = 1;
  n2 = 2;
  Matrix M3(4, 3, A);
  M3.SumRows(n1, n2, k);
  printf("After SumRows first and second. Coef = 3\n");
  M3.Display();

printf("//-/-/-/-/-/-/-/-/-/-/-/-/-/-/-//\n\n");

  printf("Second tests \n");
  n1 = 0;
  n2 = 2;
  Matrix M4(4, 3, A);  //square constructor
  printf("Initial Matrix \n");
  M4.Display();
  printf("\nAfter SwapRows zero and second\n");
  M4.SwapRows(n1, n2);
  M4.Display();

  n = 2;
  k = 0;
  Matrix M5(4, 3, A);
  printf("After ProdRows. Coef = 0\n");
  M5.ProdRows(n, k);
  M5.Display();

  n = 5;
  k = 6;
  Matrix M6(4, 3, A);
  printf("After ProdRows. n = 5\n");
  M6.ProdRows(n, k);
  M6.Display();

  k = 0;
  n1 = 1;
  n2 = 2;
  Matrix M7(4, 3, A);
  M7.SumRows(n1, n2, k);
  printf("After SumRows first and second. Koef = 0\n");
  M7.Display();

  k = 5;
  n1 = 1;
  n2 = 5;
  Matrix M8(4, 3, A);
  M8.SumRows(n1, n2, k);
  printf("After SumRows first and fifth.\n");
  M8.Display();

printf("//-/-/-/-/-/-/-/-/-/-/-/-/-/-/-//\n\n");

  printf("Third tests \n");
  n1 = 1;
  n2 = 1;
  Matrix M9(1, 3, B);  //square constructor
  printf("Initial Matrix \n");
  M9.Display();
  printf("\nAfter SwapRows first and first.\n");
  M9.SwapRows(n1, n2);
  M9.Display();

  n = 1;
  k = 3;
  Matrix M10(1, 3, B);
  printf("After ProdRows. Coef = 3\n");
  M10.ProdRows(n, k);
  M10.Display();

  n1 = 1;
  n2 = 1;
  k = 3;
  Matrix M12(1, 3, B);
  M12.SumRows(n1, n2, k);
  printf("After SumRows first and first. Coef = 3\n");
  M12.Display();

  n1 = 1;
  n2 = 2;
  Matrix M14(3, 1, B);
  printf("Initial Matrix \n");
  M14.Display();
  printf("\nAfter SwapRows first and second.\n");
  M14.SwapRows(n1, n2);
  M14.Display();

  n = 3;
  k = 3;
  Matrix M11(3, 1, B);
  printf("After ProdRows. n = 3, coef = 3\n");
  M11.ProdRows(n, k);
  M11.Display();

  k = 3;
  n1 = 1;
  n2 = 2;
  Matrix M13(3, 1, B);
  M13.SumRows(n1, n2, k);
  printf("After SumRows first and second. Coef = 3\n");
  M13.Display();

printf("//-/-/-/-/-/-/-/-/-/-/-/-/-/-/-//\n\n");

  printf("Forth tests \n");
  printf("Initial matrix - free\n");
  Matrix C1(0,0,A);
  printf("\nAfter SwapRows\n");
  C1.SwapRows(0,0);
  C1.Display();

  Matrix C2(0,0,A);
  printf("\nAfter ProdRows\n");
  C2.ProdRows(0,0);
  C2.Display();

  Matrix C3(0,0,A);
  printf("\nAfter ProdRows\n");
  C3.SumRows(0,0,0);
  C3.Display();
  getch();
}