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
{
   rows = n;
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

Matrix::Matrix(FILE * fp)
{
  fscanf(fp, "%d", &rows);
  fscanf(fp, "%d", &cols);
  elem = (double *)malloc(rows * cols * sizeof(double));
  double *p = elem;
  for (unsigned i = 0; i < rows*cols; i++, p++)
    fscanf(fp, "lf", p);
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
{
  if (j == 0 || j > (*Matrix::mPtr).cols)
    return *((double*)NULL);
  return *(ptr + j - 1);
}

Matrix::a__RowPtr::a__RowPtr(double * p)
{
  ptr = p;
}

Matrix::a__RowPtr Matrix::operator[](unsigned i) const
{
  mPtr = (Matrix*)this;
  if(i == 0 || i > rows)
    return a__RowPtr((double*)NULL);
  return a__RowPtr(elem + (i-1)*cols);
}