#define _CRT_SECURE_NO_WARNINGS
//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//#include "ReadImage.h"
#include "Graph.h"
#include "math.h"

double t, T, x, y02, y2_old, z;
double y1_old;
double y01;
int n, i;
//double *y;
double y[1000];
double a = 0;
double b = 1;

double f1(double x, double z)
{
	return z;
}
double f2(double x, double y, double z)
{
	return -2 * z - y;
}
double f(double x);

void Read();
void Calc();
//void Print();
void Draw();

int main()
{
	Read();
	//y = (double*)malloc(n * sizeof(double));
	//Calc();
	//Print();
	Draw();
	getchar();
	return 0;
}

void Read()
{
	
	T = 1;
	t = 0.1;	
}

void Calc()
{
	/*y[0] = 3;
	for (int i = 1; i < n; i++)
	{
		y[i] = y[i - 1] + t * (-1 * (y[i-1])*(y[i-1]));
	}*/
	/*x = 0; y1_old = 1, y2_old = 0;
	n = (T - x) / t;
	for (i = 0; i <= n; i++)
	{
		y01 = y1_old + t * f1(x,y2_old);
		y02 = y2_old + t * f2(x, y1_old, y2_old);
		y1_old = y01;
		y2_old = y02;
		x += t;
		y[i] = y01;
	}*/
}
/*
void Print()
{
	FILE * fw;
	fw = fopen("output.txt", "w");
	  fprintf(fw, "%lf", y[n - 1]);
	  fclose(fw);
	printf("%lf", y[n-1]);
}*/

void Draw()
{
	SetColor(250, 250, 250);
	SetWindow(0, 1, -0.1, 2);
	SetColor(0, 0, 0);
	xyLine(0, 0, 1, 1); 

	SetColor(0, 0, 200);
	double step = (b - a) / 1000;
	double x = a;
	SetPoint(x, f(x));
	for (int i = 0; i<1000; i++)
	{
		x += step;
		Line(x, f(x));
	}
	
	FILE * fp;
	fp = fopen("output1.txt", "r");
	for (int i = 0; i < 1000; i++)
	{
		fscanf(fp, "%lf", &y[i]);
		printf("%lf\n", y[i]);
	}
	fclose(fp);
	
	SetColor(200, 0, 0);
	x = a;
	step = 0.1;
	SetPoint(x, y[0]);
	for (int i = 0; i<n; i++)
	{
		printf("%lf\n", y[i]);
		x += step;
		Line(x, y[i]);
	}
	
	CloseWindow();
}

double f(double x)
{
	return exp(-x) + x*exp(-x);
}
