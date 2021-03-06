//#define _CRT_SECURE_NO_WARNINGS
//#include "stdafx.h"
#include <stdio.h>
//#include <stdlib.h>
#include <malloc.h>
//#include "ReadImage.h"
#include "Graph.h"

long double T;
long double t;
int n;
long double *y;
double a = 0;
double b = 10;

double f(double x);

void Read();
void Calc();
void Print();
void Draw();

int main()
{
	Read();
	y = (long double*)malloc(n * sizeof(long double));
	Calc();
	Print();
	Draw();
	getchar();
	return 0;
}

void Read()
{
	FILE * fp;
	fp = fopen("in.txt", "r");
	  fscanf(fp, "%lf", &T);
	  fscanf(fp, "%lf", &t);
	fclose(fp);

	n = T / t;	
}

void Calc()
{
	y[0] = 3;
	for (int i = 1; i < n; i++)
	{
		y[i] = y[i - 1] + t * (-1 * (y[i-1])*(y[i-1]));
	}
}

void Print()
{
	FILE * fw;
	fw = fopen("output.txt", "w");
	  fprintf(fw, "%LF", y[n - 1]);
	  fclose(fw);
	printf("%LF", y[n-1]);
}

void Draw()
{
	SetColor(250, 250, 250);
	SetWindow(0.6, 1.1, -0.3, 1);
	SetColor(0, 0, 0);
	xyLine(0.6, 0, 0.1, 0.1);

	SetColor(0, 200, 0);
	double step = (b - a) / 200;
	double x = a;
	SetPoint(x, f(x));
	for (int i = 0; i<200; i++)
	{
		x += step;
		Line2(x, f(x));
	}

	//SetColor(200,0,0);
	//double step2=(b-a)/5;
	////double x=a;
	//SetPoint(xk,0);
	//for (int i=0; i<5; i++)
	//{ 
	//x+=step2;
	//Line(xk,f(xk));
	//}
	CloseWindow();
}

double f(double x)
{
	return 1 / (x + 1 / 3);
	//return (sin(x) + pow(x,7) - 1);
}
