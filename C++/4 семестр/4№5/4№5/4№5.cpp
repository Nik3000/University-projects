//#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

long double T;
long double t;
int n;
long double *y;

void Read();
void Calc();
void Print();

int main()
{
	Read();
	y = (long double*)malloc(n * sizeof(long double));
	Calc();
	Print();
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