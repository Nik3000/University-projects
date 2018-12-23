#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <conio.h>

class Matrix
{
  protected:
  unsigned int rows, cols;
  double * elem;
  bool simpleCopy;
  static Matrix * mPtr;

  private:
  //Secret Constructors
  Matrix(unsigned n, unsigned m);
  Matrix(unsigned n);

  public:

  class a__RowPtr
  {
    double *ptr;
    public:
    a__RowPtr(void){};
    a__RowPtr(double *);
    double& operator[](unsigned i) const;
  };

  // Constructors
  Matrix(); //Free constructor
  Matrix(unsigned n, unsigned m, double * p); //rectangle construct
  Matrix(unsigned n, double * p); //square construct
  Matrix(const Matrix& A); //copy construct
  Matrix(FILE * fp);  //read constructor

  //Info functions
  double * ElemPtr()const;
  unsigned Rows() const;
  unsigned Cols() const;

  //Debug
  void Display() const;

  a__RowPtr operator[](unsigned i) const;

  //operator =
  Matrix& operator=(const Matrix& A);

  // Destructor
  Matrix::~Matrix();
}; // end of class Matrix