//#include <cstdlib>
//#include <stdio.h> 
//#include <math.h>
//#include <ctime>

#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <ctime>

// Формула гиперболического косинуса:
//ch(x) = 1 + x^2 / 2! + x^4 / 4! + ...

double eps;  // Погрешность
double x[10];  // Число
double factorial;  // Увеличение факториала
double StepFactorial;  // Шаг факториала
double ch[10];  // Мой гиперболический косинус
double LastCh;  // Предыдущее значение гиперболического косинуса
double StepKv;  // Шаг степени числа
double kv;  //  Увеличение степени числа
int n = 10;

int main ()
{
//--//--//--//--Ввод--//--//--//--//--//--//--//--//--//
	
	char pust[100];
	FILE *fp;
    fp=fopen("in.txt","r");
    fscanf(fp,"%s",pust);
    fscanf(fp,"%lf",&eps);
    fscanf(fp,"%s",pust);
    for (int i = 0; i < n; i++)
    {
		fscanf(fp,"%lf",&x[i]);
	}
	fclose(fp);

//--//--//--//--Алгоритм--//--//--//--//--//--//--//--//

	for (int i = 0; i < n; i++)
{
	StepKv = x[i] * x[i];
	kv = StepKv;
	factorial = 2;
	StepFactorial = 2;
	ch[i] = 1;
	LastCh = 0;
	
	while (fabs(LastCh - ch[i]) > eps)
	{
	LastCh = ch[i];

	ch[i] += kv/factorial;

	kv *= StepKv;

	StepFactorial++;
	factorial *= StepFactorial;

	StepFactorial++;
	factorial *= StepFactorial;
	}
}
//--//--//--//--Вывод--//--//--//--//--//--//--//--//

	FILE *pf;
	pf=fopen("out.txt","w");
	
	fprintf(fp,"  ch               cosh               Погрешность\n\n");
	for (int i = 0; i < n; i++)
	{
		fprintf(fp,"%15lf%15lf%15lf\n\n", ch[i], cosh(x[i]), cosh(x[i]) - ch[i]);
	}
	
	fclose(pf);
}
