#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include "Graph.h"
#include <math.h>

using namespace std;

double a, b, c, d;
int Count;
double *node;
double *Value;

double f(double x);
double Lograng(double x);
void Read();
void ArrayXY();
int remakeColor(int color);

int main()
{
  SetWindow(a,b,c,d);

  Read();

  double Nx = 1., Ny = 0.1;
  int delPlot = 100;
  double xStep = (b - a)/delPlot;

  printf("xStep = %lf\n", xStep);

  SetColor(250,250,250);
	SetWindow(a,b,c,d);

	SetColor(0,0,0);
	xyLine(0,0,Nx,Ny);

  SetColor(255,0,0);
  double x=a;
  SetPoint(x,f(x));
  for (int i = 0; i < delPlot; i++)
  {
    x+=xStep;
    Line(x,f(x));
  }
  
  ArrayXY();
  
  SetColor(0,0,255);
  xStep = (b - a)/delPlot;
  x=a;
  SetPoint(x,Lograng(x));
  for (int i = 0; i < delPlot; i++)
  {
    x+=xStep;
    Line(x,Lograng(x));
  }
  
  CloseWindow();
};

double f(double x)
{
  return 1/(0.00059+x);
};

double Lograng(double x)
{
  double multi;
  double sum = 0;
  for (int i = 0; i < Count; i++)
  {
    multi = 1;
    for (int j = 0; j < Count; j++)
    {
      if (j==i)
        {continue;}
      multi *= (x-node[j]) / (node[i]-node[j]);
    }
    sum += Value[i]*multi;
  }
  return sum;
};

void ArrayXY()
{

  node = new double[Count];
  Value = new double[Count];
  double xStep = (b - a)/(Count-1);
  node[0] = a;
  node[Count-1] = b;
  Value[0] = f(a);
  Value[Count-1] = f(b);

  for (int i = 1; i < Count-1; i++)
  {
    node[i] = a + xStep*i;
    Value[i] = f(node[i]);
  }

  for (int i = 0; i < Count; i++)
  {
    printf("node[%d] = %lf\n", i, node[i]);
    printf("Value[%d] = %lf\n\n", i, Value[i]);
  }
};

void Read()
{
	char pust[100];
	FILE *fp;
	fp = fopen ("input.txt", "r");

	fscanf(fp, "%s", pust);
	fscanf(fp, "%s", pust);
	fscanf(fp, "%s", pust);
	fscanf(fp, "%lf", &a);

	fscanf(fp, "%s", pust);
	fscanf(fp, "%s", pust);
	fscanf(fp, "%lf", &b);

	fscanf(fp, "%s", pust);
	fscanf(fp, "%s", pust);
	fscanf(fp, "%lf", &c);

	fscanf(fp, "%s", pust);
	fscanf(fp, "%s", pust);
	fscanf(fp, "%lf", &d);

	fscanf(fp, "%s", pust);
	fscanf(fp, "%s", pust);
	fscanf(fp, "%d", &Count);
	
  printf("a = %lf\n", a);
  printf("b = %lf\n", b);
  printf("c = %lf\n", c);
  printf("d = %lf\n", d);
  printf("node = %d\n", Count);
  fclose(fp);
};

int remakeColor(int color)
{
	return (color < 0)?(color+=256):(color);
};
