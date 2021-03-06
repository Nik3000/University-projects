#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "math.h"

double f1(double x, double z)
{
	return z;
}

double f2(double x, double y, double z)
{
	return -2 * z - y;
}

double solve(double x)
{
	return exp(-x) + x*exp(-x);
}

int i, n, T;
double x, y_last, z_last, t, y_new, z_new;

void Read();
void Calc();
void Print();

int main()
{
	Read();
	Calc();
	Print();
	getchar();
    return 0;
}

void Read()
{
	t = 0.000001;
	T = 1;
	x = 0;
	n = (T - x) / t;
	y_last = 1;
	z_last = 0;
}

void Calc()
{
	for (int i = 0; i < n; i++)
	{
		y_new = y_last + f1(x, z_last)*t;
		z_new = y_last + f2(x, y_last, z_last)*t;
		y_last = y_new;
		z_last = z_new;
		x += t;
	}
}

void Print()
{
	printf("%lf\n", x);
	printf("%lf\n", y_new);
	printf("%lf", solve(1));
}