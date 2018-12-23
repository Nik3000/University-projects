#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Matrix.hpp"

Matrix * Matrix::mPtr = NULL;

//Secret Constructors

Matrix::Matrix(unsigned n): simpleCopy(false)  //square secret constructor
{
  rows = n;
  cols = n;
  elem = (double *)malloc(rows * cols * sizeof(double));
}

Matrix::Matrix(unsigned n, unsigned m): simpleCopy(false) //rectangle secret constructor
  {rows = n;
   cols = m;
   elem = (double *)malloc(rows * cols * sizeof(double));
  }

//Constructors
Matrix::Matrix(void): simpleCopy(false) //free constructor
{
  rows = 0;
  cols = 0;
  elem = NULL;
}

Matrix::Matrix(unsigned n, double * p): simpleCopy(false) //square constructor
{
  rows = n;
  cols = n;
  elem = (double *)malloc(rows * cols * sizeof(double));
  memcpy(elem, p, rows* cols * sizeof(double));
}

Matrix::Matrix(unsigned n, unsigned m, double * p): simpleCopy(false) //rectangle constructor
{
  rows = n;
  cols = m;
  elem = (double *)malloc(rows * cols * sizeof(double));
  memcpy(elem, p, rows * cols * sizeof(double));
}

Matrix::Matrix(const Matrix& A): simpleCopy(false) //copy constructor
{
  rows = A.rows;
  cols = A.cols;
  if(A.simpleCopy)  // to avoid getting new memory block
    elem = A.elem;
  else              // normal functionality
  {
    elem = (double *)malloc(rows * cols * sizeof(double));
    memcpy(elem, A.elem, rows * cols * sizeof(double));
  }
}

Matrix::~Matrix() //destructor
{
  if(simpleCopy) return;    // defence from destructor attack
  if(elem == NULL) return;  // nothing to do
  free(elem);
  elem = NULL;
  rows = cols = 0;
}

//Methods
void Matrix::Display() const  //for debug
{
  double * p = elem;
  for(unsigned i=0; i < rows; i++)
  {
    for(unsigned j = 0; j < cols; j++, p++)
      printf("%10.3lf", *p);
    printf("\n");
  }
  printf("\n");
}

Matrix& Matrix::operator=(const Matrix &A)
{
  if(this == &A) return *this;
  if(elem != NULL)
    free(elem);
  rows = A.rows;
  cols = A.cols;
  elem = (double*) malloc(rows * cols * sizeof(double));
  memcpy(elem, A.elem, rows * cols * sizeof(double));
  return *this;
}

double& Matrix::a__RowPtr::operator[](unsigned j) const
{ if (j == 0 || j > (*Matrix::mPtr).cols)
    return *((double*)NULL);
  return *(ptr + j - 1);
}

Matrix::a__RowPtr::a__RowPtr(double * p)
  {ptr = p;
  }

Matrix::a__RowPtr Matrix::operator[](unsigned i) const
{
  mPtr = (Matrix*)this;
  if(i == 0 || i > rows)
    return a__RowPtr((double*)NULL);
  return a__RowPtr(elem + (i-1)*cols);
}

//Methods
void Matrix::SwapRows(unsigned n1, unsigned n2)
{
  double k;
  double *p = elem;
  if (elem != NULL)
  {
    if (n1 > 0 and n2 > 0 and n1 <= rows and n2 <= rows)
    {
      n1 -= 1;
      n2 -= 1;
      for(int i = 0; i < cols; i++, p++)
      {
        k = *(p + n1 * cols);
        *(p + n1 * cols) = *(p + n2 * cols);
        *(p + n2 * cols) = k;
      }
    }
    else
      printf("Eror: numbers of the entered lines are outside bounds of the matrix dimension\n");
  }
  else
    printf("Eror: free matrix");
}

void Matrix::ProdRows(unsigned n, double k)
{
  double *p = elem;
  if (elem != NULL)
  {
    if (n > 0 and n <= rows and k != 0)
    {
      n -= 1;
      for(int i = 0; i < cols; i++, p++)
        *(p + n * cols) = *(p + n * cols) * k;
    }
    else
      printf("Eror: number of the entered lines are outside bounds of the matrix dimension or product coefficient = 0\n");
  }
  else
    printf("Eror: free matrix");
}

void Matrix::SumRows(unsigned n1, unsigned n2, double k)
{
  double *p = elem;
  if (elem != NULL)
  {
    if (n1 > 0 and n2 > 0 and n1 <= rows and n2 <= rows and k != 0)
    {
      n1 -= 1;
      n2 -= 1;
      for(int i = 0; i < cols; i++, p++)
        *(p + n1 * cols) = *(p + n1 * cols) + *(p + n2 * cols) *k;
    }
    else
      printf("Eror: numbers of the entered lines are outside bounds of the matrix dimension or product coefficient = 0\n");
  }
  else
    printf("Eror: free matrix");
}