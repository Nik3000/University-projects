#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

double f(double x, double y)
{
	return x * x - y * y;
}
int main()
{
	int n, m, x, y, it_num;
	double h;
	ifstream kot("in.txt");
	kot >> h;
	kot >> it_num; //количество итераций
	kot >> x; //координата по x
	kot >> y; //координата по y
	kot.close();
	n = 1. / h;
	m = 2. / h;
	double *U, *u;
	U = new double[(m + 1)*(n + 1)];
	u = new double[(m + 1)*(n + 1)];
	double time;
	clock_t timeBegin, timeEnd;
	timeBegin = clock();
	//заплнение граничных точек
	for (int j = 0; j <= n; j++)
		for (int i = 0; i <= m; i++)
		{
			u[i*(n + 1) + j] = f(i*h, j*h);
			U[i*(n + 1) + j] = u[i*(n + 1) + j];
		}
	for (int j = 1; j < n; j++)
		for (int i = 1; i < m; i++)
		{
			u[i*(n + 1) + j] = 0;
		}
	for (int k = 0; k < it_num; k++)
	{
		for (int j = 1; j < n; j++)
			for (int i = 1; i < m; i++)
				U[i*(n + 1) + j] = 0.25 * (u[(i + 1)*(n + 1) + j] + u[(i - 1)*(n + 1) + j] + u[i*(n + 1) + j + 1] + u[i*(n + 1) + j - 1]);
		swap(U, u);
	}
	timeEnd = clock();
	time = timeEnd - timeBegin;

	ofstream put("output.txt");
	for (int j = 0; j <= n; j++)
	{
		put.precision(2);
		for (int i = 0; i <= m; i++)
			put << abs(U[i*(n + 1) + j] - f(i*h, j*h)) << ' ';
		put << endl;

	}
	put << f(x*h, y*h) - U[x*y] << endl;
	put << "Время работы: " << time << endl;
	put.close();
	system("pause");
}

